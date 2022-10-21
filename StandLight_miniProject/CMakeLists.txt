cmake_minimum_required(VERSION 3.0.0)

project(StandLight)
#cpp file이 있는 위치를 넣어준다. 
add_executable(${PROJECT_NAME}
    ./src/main.cpp
    ./src/app/Listener/Listener.cpp
    ./src/app/Controller/Controller.cpp
    ./src/app/View/View.cpp
    ./src/app/Service/Service.cpp
    ./src/hw/Button/Button.cpp
    ./src/hw/Led/Led.cpp
    ./src/hw/ClockCheck/ClockCheck.cpp
    ./src/app/Service/ClockService.cpp
    ./src/app/View/ClockView.cpp
    ./src/hw/LCD/LCD.cpp
    ./src/hw/I2C/I2C.cpp
    ./src/hw/DHT11/DHT11.cpp
    ./src/app/Service/TempHumidService.cpp
    ./src/app/View/TempHumidView.cpp
    ./src/hw/UltraSonic/UltraSonic.cpp
    ./src/hw/PWM/PWM.cpp
    ./src/app/Service/PWMService.cpp
    ./src/app/Service/TimerService.cpp
    ./src/app/View/PWMView.cpp
    ./src/app/View/TimerView.cpp
)
# header가 있는 위치를 넣어준다. 
target_include_directories(${PROJECT_NAME} PUBLIC
    ./src/app/Listener
    ./src/app/Controller
    ./src/app/Service
    ./src/app/View
    ./src/hw/Button
    ./src/hw/Led
    ./src/hw/ClockCheck
    ./src/hw/LCD
    ./src/hw/I2C
    ./src/hw/DHT11
    ./src/hw/UltraSonic
    ./src/hw/PWM
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)