/* 
 * File:   SuperCon-badge-animate.c
 * Author: szczys@hotmail.com
 *
 * User code should be placed in this file. Follow the examples below:
 *   Write to display through Buffer[] and call displayLatch() to show changes on badge
 *   use getTime() for upcounting (approximate) milliseconds for non-blocking delays
 *   call getControl() to return a key mask of debounced button presses
 *   call pollAccel() to populate accelerometer data and read AccX(high/low), AccY(high/low), AccZ(high/low)
 *
 * MIT License (see license.txt)
 * Copyright (c) 2016 Hackaday.com
 */

#include "HaD_Badge.h"

uint8_t HEIGHT = 35;
uint8_t WIDTH = 45;

#define FP_SHIFT 8 // 2^8 = 256
#define FP_MASK ((1 << FP_SHIFT) - 1) // 256 (all LSB set, all MSB clear)
#define FP_INTEGER_PART(arg) (arg >> FP_SHIFT)
#define FP_FRACTION_PART(arg) (arg & FP_MASK)



uint16_t ballX = (2<<FP_SHIFT);
uint16_t ballY = (2<<FP_SHIFT);

uint8_t lastBallX = 0;
uint8_t lastBallY = 0;

uint8_t coef = 6;

//Hint: look in HaD_Badge.h for function and constant definitions
uint8_t isLit(uint8_t x, uint8_t y) {
     if (Buffer[y] & (1 << (7 - x))) {
         return 1;
     }
     return 0;
 }

extern uint8_t maze[210];
void drawMaze(int8_t x, int8_t y) {
    for (uint8_t i = 0; i < TOTPIXELY; i++ ) {
        if ((y + i) < 0 || (y + i > HEIGHT)) {
            Buffer[i] = 0;
        } else {
            uint8_t byteOffset = ((y + i) * ((WIDTH + WIDTH % 8) / 8) + x / 8);
            uint8_t bitOffset = x % 8;
            if (x < 0) {
                Buffer[i] = maze[byteOffset] >> -1 * x;
            } else if (x > WIDTH - 8) {
                byteOffset = ((y + i) * ((WIDTH + WIDTH % 8) / 8) + (WIDTH - 8) / 8);
                bitOffset = (WIDTH - 8) % 8;
                Buffer[i] = (maze[byteOffset] << bitOffset | maze[byteOffset+1] >> (8 - bitOffset)) << (x - (WIDTH - 8));
            } else {
                Buffer[i] = maze[byteOffset] << bitOffset | maze[byteOffset+1] >> (8 - bitOffset);
            }
        }
    }
}

uint8_t worldPosX = 0;
uint8_t worldPosY = 0;

void updateBall() {
    uint8_t curX = FP_INTEGER_PART(ballX);
    uint8_t curY = FP_INTEGER_PART(ballY);
    if(curX != lastBallX || curY != lastBallY) {
        
        worldPosX = curX;
        worldPosY = curY;
        
        lastBallX = curX;
        lastBallY = curY;
    }
}

void moveLeft() {
    if (FP_INTEGER_PART(ballX) > 1) {
        //only move if we're not already at the edge
        ballX -= AccXhigh * coef;
    }
}

void moveRight() {
    if (FP_INTEGER_PART(ballX) < WIDTH-1) {
        //only move if we're not already at the edge
        ballX += (0xFF - AccXhigh) * coef;
    }
}

void moveUp() {
    if (FP_INTEGER_PART(ballY) > 1) {
        //only move if we're not already at the edge
        ballY -= AccYhigh * coef;
    }
}

void moveDown() {
    //Limit ball travel to top 8 rows of the screen
    if (FP_INTEGER_PART(ballY) < HEIGHT - 1) {
        //only move if we're not already at the edge
        ballY += (0xFF - AccYhigh) * coef;

    }
}

void animateBadge(void) {

    int8_t x = 0;
    int8_t y = 0;
    
    uint32_t nextTime = getTime();
    
    int16_t tempMinAccel = 0;
    int16_t tempMaxAccel = 0;
    
    int16_t minAccel = 0;
    int16_t maxAccel = 0;
    
    int16_t xAccel;
    
    int16_t deltaTime = 100;
    while(1) {

        //This shows how to use non-blocking getTime() function
        
        uint8_t direction;
        if (getTime() <= nextTime) {
            continue;
        }
        //Use accelerometer to draw left or right arrow for X axis
        pollAccel();    //Tell kernel to read the accelerometer values
        nextTime = getTime()+deltaTime;
    
    updateBall();
    while(1) {
        
        pollAccel();    //Tell kernel to read the accelerometer values
        if (AccXhigh < 0xF0 && !isLit(3, 7)) {
            moveLeft();
        }
        if (AccXhigh > 0xF0 && !isLit(5, 7)) {
            moveRight();
        }
        if (AccYhigh < 0xF0 && !isLit(4, 6)) {
            moveUp();   
            
        }
        if (AccYhigh > 0xF0 && !isLit(4, 8)) {
            moveDown();
        }
        
        switch(getControl()) {
            case UP:
                if (y > -10) {
                    y--;
                }
                break;
            case DOWN:
                if (y < HEIGHT - 6) {
                    y++;
                }
                break;
            case RIGHT:
                if (x < WIDTH - 5) {
                    x++;
                }
                break;
            case LEFT:
                if (x > -3) {
                    x--;
                }
                break;
            default:
                break;
        }
        updateBall();
        drawMaze(worldPosX-4, worldPosY-7);
        // displayPixel();
        displayPixel(4, 7, ON);
    }
    }
}

