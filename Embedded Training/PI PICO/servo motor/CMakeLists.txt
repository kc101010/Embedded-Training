cmake_minimum_required(VERSION 3.12)

# include pico sdk in project
include(pico_sdk_import.cmake)

project(servo C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# init sdk
pico_sdk_init()

add_executable(servo
    servo.c
)

# link pico stdlib to exe
target_link_libraries(servo pico_stdlib hardware_pwm)

# 
pico_add_extra_outputs(servo)
