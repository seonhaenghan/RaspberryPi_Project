cmake_minimum_required(VERSION 3.0.0)

project(ledblink)

add_executable(${PROJECT_NAME}
    main.cpp
    hw/led/LED.cpp
    hw/button/button.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    hw/led
    hw/button
)
   

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)

    

