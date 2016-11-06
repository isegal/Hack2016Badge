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

uint8_t ballX = 4;
uint8_t ballY = 8;
uint8_t gapSize = 2;
uint8_t HEIGHT = 35;
uint8_t WIDTH = 45;


//Hint: look in HaD_Badge.h for function and constant definitions


extern uint8_t maze[210];
void drawMaze(uint8_t x, uint8_t y) {
    
    
    
    for (uint8_t i =  0; i < TOTPIXELY; i++ ) {
        uint8_t byteOffset = ((y + i) * ((WIDTH + WIDTH % 8) / 8) + x / 8);
        uint8_t bitOffset = x % 8;
        if ((y + i) < 0 || (y + i > HEIGHT)) {
            Buffer[i] = 0;
        } else {
            if (x < 0) {
                Buffer[i] = maze[byteOffset] >> -1 * x;
            } else if (x > WIDTH - 8) {
                Buffer[i] = maze[byteOffset+1] << (x - WIDTH - 8);
            } else {
                Buffer[i] = maze[byteOffset] << bitOffset | maze[byteOffset+1] >> (8 - bitOffset);
            }
        }
    }
}

//void drawLineWithGap(uint8_t posY) {
//    //uint8_t gapIndex = getTime() % (TOTPIXELX - 1);
//    uint8_t gapIndex = 2;
//    Buffer[posY] = 0;
//    for (uint8_t i = 0; i < gapSize; i++) {
//        Buffer[posY] |= (1 << (TOTPIXELX - gapIndex - 1 - i));
//    }
//    Buffer[posY] = ~Buffer[posY];
//}
void animateBadge(void) {
    //displayPixel(ballX, ballY, ON);
    //displayLatch();

    uint8_t x = 0;
    uint8_t y = 0;
    
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
        if (AccXhigh < 0xF0 && AccXhigh >= 0x01) {
            direction = LEFT;
            
        }
        if (AccXhigh > 0xF0 && AccXhigh <= 0xFE) {
            direction = RIGHT;
        }
        if (AccYhigh < 0xF0 && AccYhigh >= 0x01) {
            direction = UP;
        }
        if (AccYhigh > 0xF0 && AccYhigh <= 0xFE) {
            direction = DOWN;
        }
        nextTime = getTime()+deltaTime;

        
        switch (getControl()) {
            case (ESCAPE):
                displayClose();
                return;
            case (UP):
                deltaTime += 20;
                break;
            case (DOWN):
                deltaTime -= 20;
                break;
            default:
                break;
        }
        
        switch(direction) {
            case UP:
                if (y > -3) {
                    y--;
                }
                break;
            case DOWN:
                if (y < HEIGHT - 13) {
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
        drawMaze(x, y);
    }
}

