#include "allcode_api.h"
#include "setup.h"

void setup() {
    /* initialise robot and reset encoders */
    FA_RobotInit();
    FA_ResetEncoders();
    
    /* clear display and wait for bluetooth connection */
    FA_LCDClear();
    FA_LCDBacklight (75);
    FA_LCDPrint("Waiting for BT", 14, 20, 25, FONT_NORMAL, LCD_OPAQUE);

    while(FA_BTConnected() == 0 && FA_ReadSwitch(0) == 0) {} /* wait for bluetooth */

    if (FA_BTConnected() == 1) {
        FA_LCDClear();
        FA_LCDPrint("BT Connected", 12, 20, 25, FONT_NORMAL, LCD_OPAQUE);
        FA_BTSendString("Connection established\n", 30);
    }

    /* wait for 1 sec, then clear display */
    unsigned long endTime = FA_ClockMS() + 1000;
    while (FA_ClockMS() < endTime) {}

    FA_LCDClear();
    FA_LCDBacklight (10);
    FA_BTSendString("Setup finished\n", 30);
}