file(GLOB SOURCES *.c *.h)
add_library(neuralnetTest ${SOURCES})

target_link_libraries(neuralnetTest neuralnet)