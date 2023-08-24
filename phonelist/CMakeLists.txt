cmake_minimum_required(VERSION 3.25)
project(phonelist C)

set(CMAKE_C_STANDARD 11)

add_executable(phonelist test.c contact.c contact.h)
