cmake_minimum_required(VERSION 3.0.0) 
#해당 Cmake 파일은 3.0.0 이상이면 된다.
project(tcpClient)

add_executable(${PROJECT_NAME}
   ./tcpClient.cpp
)
#실행되는 File의 이름은 Project name과 동일하다.

target_include_directories(${PROJECT_NAME} PUBLIC
    
)
#header 추가 

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)
#위에 있는 실행 file을 타겟으로 라이브러리를 링크함 

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)
#compile 옵션으로 warning을 설정 함