file(GLOB SOURCES *.c *.h)
add_library(pvpanel ${SOURCES})

target_link_libraries(pvpanel m)