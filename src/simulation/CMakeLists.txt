file(GLOB SOURCES *.c *.h)
add_library(simulation ${SOURCES})

target_link_libraries(simulation m neuralnet helper)