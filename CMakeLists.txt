cmake_minimum_required(VERSION 3.17)
project(TestClient C)

set(CMAKE_C_STANDARD 99)

add_executable(TestClient main.c warp.h warp.c)