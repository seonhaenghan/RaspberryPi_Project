#ifndef BUTTON_H
#define BUTTON_H

enum {NO_ACTIVE, PUSH_ACTIVE, RELEASE_ACTIVE};
// 열거형 

class Button
{
private:
    const int PUSHED = 0;
    const int RELEASED = 1; // 상수 선언 
    int prevState;
    int pinNum; 

public:
    Button(int pin); // 생성자 
    ~Button(); // 소멸자 
    int getState();
};

#endif