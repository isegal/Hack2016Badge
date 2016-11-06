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

#define FP_SHIFT 8 // 2^8 = 256
#define FP_MASK ((1 << FP_SHIFT) - 1) // 256 (all LSB set, all MSB clear)
#define FP_INTEGER_PART(arg) (arg >> FP_SHIFT)
#define FP_FRACTION_PART(arg) (arg & FP_MASK)


uint16_t ballX = (4<<FP_SHIFT);
uint16_t ballY = (8<<FP_SHIFT);

uint8_t lastBallX = 0;
uint8_t lastBallY = 0;

const char msg[] = "HELLOZHOUTHISISIV";


//Hint: look in HaD_Badge.h for function and constant definitions

void eraseBall() {
    //uses global variables to erase current ball
    displayPixel(lastBallX, ballY, OFF);
    displayLatch();
}


void updateBall() {
    uint8_t curX = FP_INTEGER_PART(ballX);
    uint8_t curY = FP_INTEGER_PART(ballY);
    if(curX != lastBallX || curY != lastBallY) {
        displayPixel(lastBallX, lastBallY, OFF);
        displayPixel(curX, curY, ON);
        lastBallX = curX;
        lastBallY = curY;
    }
}

void moveLeft() {
    if (FP_INTEGER_PART(ballX) > 0) {
        //only move if we're not already at the edge
        --ballX;
    }
}

void moveRight() {
    if (FP_INTEGER_PART(ballX) < TOTPIXELX-1) {
        //only move if we're not already at the edge
        ++ballX;
    }
}

void moveUp() {
    if (FP_INTEGER_PART(ballY) > 0) {
        //only move if we're not already at the edge
        --ballY;
    }
}

void moveDown() {
    //Limit ball travel to top 8 rows of the screen
    if (FP_INTEGER_PART(ballY) < TOTPIXELY - 1) {
        //only move if we're not already at the edge
        ++ballY;

    }
}

void drawArrow(uint8_t rightOrLeft) {
    //0 == right
    //1 == left
    if (rightOrLeft) {
        Buffer[11] = 0b00100000;
        Buffer[12] = 0b01110000;
        Buffer[13] = 0b11111111;
        Buffer[14] = 0b01110000;
        Buffer[15] = 0b00100000;
    }
    else {
        Buffer[11] = 0b00000100;
        Buffer[12] = 0b00001110;
        Buffer[13] = 0b11111111;
        Buffer[14] = 0b00001110;
        Buffer[15] = 0b00000100;
    }
    displayLatch();
}

extern uint8_t Retro8x16[1524];
void drawChar(uint8_t currPos) {
    uint8_t dispChar = msg[currPos];
    uint16_t charOffset = (dispChar-65) * 16;
    for(uint8_t i = 0; i < 16; ++i) {
        Buffer[i] = Retro8x16[charOffset + i];
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
    uint8_t currChar = 0;
    //uint8_t currChar = 'A';
    uint32_t nextTime = getTime();
    
    int16_t tempMinAccel = 0;
    int16_t tempMaxAccel = 0;
    
    int16_t minAccel = 0;
    int16_t maxAccel = 0;
    
    int16_t xAccel;
    
    int8_t charColumn = 0;
    int8_t deltaAcc = 0;
    int16_t deltaTime = 100;
    
    updateBall();
    while(1) {
//        drawLineWithGap(5);
        
        //This shows how to use non-blocking getTime() function
        if (getTime() <= nextTime) {
            continue;
        }
        //Use accelerometer to draw left or right arrow for X axis
        pollAccel();    //Tell kernel to read the accelerometer values
        if (AccXhigh < 0xF0 && AccXhigh >= 0x01) {
            moveLeft();
        }
        if (AccXhigh > 0xF0 && AccXhigh <= 0xFE) {
            moveRight();
            //deltaAcc = 0xFF - AccXhigh;
        }
        if (AccYhigh < 0xF0 && AccYhigh >= 0x01) {
            moveUp();   
            
        }
        if (AccYhigh > 0xF0 && AccYhigh <= 0xFE) {
            moveDown();
        }
        nextTime = getTime()+deltaTime;
        
        updateBall();
        
        //Buffer[1] = AccXhigh;
        //Buffer[3] = AccYhigh;
        //Buffer[5] = AccZhigh;
//        if (AccXhigh < 0xF0) { drawArrow(1); } //Use high 8-bits of X value to decide what to do.
//        else { drawArrow(0); }
        
        //xAccel = (((int16_t)(AccXhigh)));
        
        //if (xAccel > tempMaxAccel) {
          //tempMaxAccel = xAccel;
        //}
        
        //if (xAccel < tempMinAccel) {
          //tempMinAccel = xAccel;
        //}
        
        //if (getTime() > nextTime) {
          //  minAccel = tempMinAccel;
            //maxAccel = tempMaxAccel;
            //tempMinAccel = 0;
            tempMaxAccel = 0;
            
           // nextTime = getTime()+1000;  //prepare next event for about 1000ms (1 second) from now
            // displayLatch();     //Make sure changes to the buffer show up on the display
        //}
        
//        normal_accel = image_num_lines + swing_direction - (int) (floor((accelG-min_accel)*(image_num_lines-1)/(max_accel-min_accel)));
//  if (normal_accel < 0){normal_accel = 0;} //ensure we don't try to get a negative array index
//  else if (normal_accel > image_num_lines - 1){normal_accel = image_num_lines - 1;}
        
       // charColumn = (xAccel - minAccel)*(sizeof(msg)-1)/maxAccel-minAccel;
        
        //if(charColumn < 0) charColumn = 0;
       // if(charColumn >= sizeof(msg)) charColumn = sizeof(msg)-1;
        
        //drawChar(charColumn);
        
        //Buffer[0] = AccXlow;
        //Buffer[1] = AccXhigh;
        
        //This shows how to get user input
        switch (getControl()) {
            case (ESCAPE):
                displayClose();
                return;
            case (LEFT):
                moveLeft();
                if (currChar > 0)
                --currChar;
                break;
            case (RIGHT):
                moveRight();
                if (currChar < sizeof(msg))
                ++currChar;
                break;
            case (UP):
                //moveUp();
                //deltaTime += 20;
                break;
            case (DOWN):
                //moveDown();
                //deltaTime -= 20;
                break;
        }
        
        // drawChar(currChar);
    }
}
