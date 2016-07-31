cmake_minimum_required(VERSION 3.5)
project(MPPTNeuralNetwork)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}") # -Wall -Werror

add_subdirectory(src)
add_subdirectory(test)