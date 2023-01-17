cmake_minimum_required(VERSION 3.5)

project(CodeStepbyStep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CodeStepbyStep main.cpp)

install(TARGETS CodeStepbyStep
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
