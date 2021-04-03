#include "allcode_api.h"
#include "setup.h"
#include "drive.h"

int main() {
    setup();
    
    /* control loop */
     while(1) {
         drive();
     }
    
    return 0;
}

