file(GLOB SOURCES *.c *.h)
add_library(perceptronTest ${SOURCES})

target_link_libraries(perceptronTest perceptron)