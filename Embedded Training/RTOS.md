#generalconcepts 

## [An Operating System on a $4 Board? | Getting Started with FreeRTOS on the Raspberry Pi Pico](https://youtu.be/5pUY7xVE2gU)

FreeRTOS, a simple solution to solve problems of systems with complex features/lots of peripherals.

### RTOS
+ Appears like a normal OS
+ Uses a scheduler to switch between threads that then gives illusions of several cores to handle various tasks
+ Allows for task priority, so manages tasks and allows for definitions of what needs to happen first

Unlike a traditional OS which has a main executable in the kernel, the RTOS is shipped as source code where the developer compiles in their own tasks to create one large binary.  

In this example Pi PICO example, all code is compiled with cmake. The RTOS is added to the build as a static library in order to keep things simple in terms of compilation/uploading. 

Library calls are added to the LED Blink example to call the core RTOS, configurations and a header with exports for the FreeRTOS task API.

Tasks are created with `xTaskCreate()` function which holds detail such as task name, the task function and priority.

`vTaskDelay()` can be used like `sleep()` but when the delay runs, it allows other tasks to be executed in the background. 

Uses Cmake and make to build project.