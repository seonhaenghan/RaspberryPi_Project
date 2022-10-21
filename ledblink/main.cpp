#include <iostream>
#include "LED.h"    // #include hw./led./LED.h/ 를 CMake가 대신 해줌 
#include "button.h"
#include <wiringPi.h>

int main()
{
    LED modeLight(21);
    LED playLight(22); // 추상화 (의미를 부여함)
    LED *warningLight = new LED(23); 

    Button modeButton(27);
    Button playButton(28);
    Button warningButton(29);
    //std::cout << "led1 object\n";

    while (1)
    {
        // modeLight.on();
        // playLight.toggle();
        // warningLight->off();
        // delay(300);
        // modeLight.off();
        // playLight.toggle();
        // warningLight->on();
        // delay(300);
        if(modeButton.getState() == RELEASE_ACTIVE)
        {
            modeLight.toggle();
        }
        if(playButton.getState() ==RELEASE_ACTIVE)
        {
            playLight.toggle();
        }
        if(warningButton.getState() ==PUSH_ACTIVE)
        {
            warningLight->toggle();
        }
        delay(50);
    }
   
    return 0;
}

