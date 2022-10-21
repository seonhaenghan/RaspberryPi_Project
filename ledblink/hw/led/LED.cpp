#include "LED.h"
#include <wiringPi.h>

LED::LED(int pin) // 소멸자
{
    pinNum = pin;
    ledState = 0;
    wiringPiSetup();
    pinMode(pinNum, OUTPUT);
}
LED::~LED() 
{
}
void LED::on()
{
    ledState = 1;
    digitalWrite(pinNum, ledState);
}
void LED::off()
{
    ledState = 0;
    digitalWrite(pinNum, ledState);
}
void LED::toggle()
{
    ledState = ledState ^ 1;
    digitalWrite(pinNum, ledState);
}