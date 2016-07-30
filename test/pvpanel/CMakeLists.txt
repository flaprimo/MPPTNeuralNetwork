file(GLOB SOURCES *.c *.h)
add_library(pvpanelTest ${SOURCES})

target_link_libraries(pvpanelTest pvpanel)