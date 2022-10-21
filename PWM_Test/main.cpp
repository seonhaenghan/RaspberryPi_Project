#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

int main()
{
    std::cout << "Hello World!!\n" << std::endl;
    wiringPiSetup();
    int pwmPin = 26;
    softPwmCreate(26, 0, 100);  // 26pin , 0~100 까지의 범위 
    while(1)
    {// 2초 간격으로 속도 변경 
        softPwmWrite(pwmPin, 40);
        delay(2000);
        softPwmWrite(pwmPin, 70);
        delay(2000);
        softPwmWrite(pwmPin, 90);
        delay(2000);
        softPwmWrite(pwmPin, 99);
        delay(2000);
    }
    return 0;
}