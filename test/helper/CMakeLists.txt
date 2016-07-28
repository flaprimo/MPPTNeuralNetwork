file(GLOB SOURCES *.c *.h)
add_library(helperTest ${SOURCES})

target_link_libraries(helperTest helper)