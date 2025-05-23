# Install script for directory: /home/kyle/pico-sdk

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/arm-none-eabi-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/mnt/15f210d7-aa4f-4ea8-a4b3-2bd52aeba8fc/Programming/Uni/Year 4 Hons/Embedded Training/Embedded Training/PI PICO/led/build/pico-sdk/tools/cmake_install.cmake")
  include("/mnt/15f210d7-aa4f-4ea8-a4b3-2bd52aeba8fc/Programming/Uni/Year 4 Hons/Embedded Training/Embedded Training/PI PICO/led/build/pico-sdk/src/cmake_install.cmake")
  include("/mnt/15f210d7-aa4f-4ea8-a4b3-2bd52aeba8fc/Programming/Uni/Year 4 Hons/Embedded Training/Embedded Training/PI PICO/led/build/pico-sdk/docs/cmake_install.cmake")

endif()

