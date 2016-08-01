file(GLOB SOURCES *.c *.h)
add_library(pvpanelnn ${SOURCES})

target_link_libraries(pvpanelnn helper neuralnet pvpanel)