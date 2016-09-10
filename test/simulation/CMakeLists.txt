file(GLOB SOURCES *.c *.h)
add_library(simulationTest ${SOURCES})

target_link_libraries(simulationTest simulation)