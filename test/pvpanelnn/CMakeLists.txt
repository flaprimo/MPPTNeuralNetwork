file(GLOB SOURCES *.c *.h)
add_library(pvpanelnnTest ${SOURCES})

target_link_libraries(pvpanelnnTest pvpanelnn)