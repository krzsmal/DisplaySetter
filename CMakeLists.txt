cmake_minimum_required(VERSION 3.30)
project(DisplaySetter)

set(CMAKE_CXX_STANDARD 20)

if(WIN32)
    set(RESOURCE_FILE resources/resource.rc)
    add_executable(DisplaySetter DisplaySetter.cpp ${RESOURCE_FILE})
else()
    message(FATAL_ERROR "This project is designed to work only on Windows.")
endif()
