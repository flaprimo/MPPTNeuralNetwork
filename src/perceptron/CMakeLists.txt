file(GLOB SOURCES *.c *.h)
add_library(perceptron ${SOURCES})

include_directories(../helper)