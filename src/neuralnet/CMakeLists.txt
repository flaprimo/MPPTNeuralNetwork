file(GLOB SOURCES *.c *.h)
add_library(neuralnet ${SOURCES})

target_link_libraries(neuralnet m helper)