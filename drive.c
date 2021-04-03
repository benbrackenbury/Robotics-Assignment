#include "allcode_api.h"
#include "drive.h"

void drive() {
    
    static unsigned short leftSpeed = 20;
    static unsigned short rightSpeed = 20;
    static short leftValue, rightValue, leftIncrement, rightIncrement;
    
    FA_ResetEncoders();
        
    FA_SetMotors(leftSpeed, rightSpeed);
    
    unsigned long endTime = FA_ClockMS() + 500;
    while (FA_ClockMS() < endTime) {}

    leftValue = FA_ReadEncoder(0);
    rightValue = FA_ReadEncoder(1);

    leftIncrement = (rightValue>leftValue) ? 1 : -1;
    rightIncrement = (leftValue>rightValue) ? 1 : -1;
    if (leftValue == rightValue) {
        leftIncrement = 0;
        rightIncrement = 0;
    }

    leftSpeed+= leftIncrement;
    rightSpeed += rightIncrement;
    
    FA_BTSendNumber(leftSpeed);
    FA_BTSendString(", ", 3);
    FA_BTSendNumber(rightSpeed);
    FA_BTSendString("\n", 3);
}