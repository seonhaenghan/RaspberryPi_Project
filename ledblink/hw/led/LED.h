#ifndef LED_H
#define LED_H

class LED // 캡슐화 변수와 함수를 묶음
{

private: // 비공개용 (변수 or 함수가 들어간다.)
         // 공개적으로 사용할 수 없음 (정보 은닉)
    int pinNum;
 
    int ledState;

public:           // 공개용
    LED(int pin); // 생성자
    ~LED();
    void on();
    void off();
    void toggle();
};

#endif
