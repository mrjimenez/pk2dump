include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_definitions("-fexceptions")

SET(pk2dump_STAT_SRCS
	PK2Dat.cpp
	pickit2dat.c
)

automoc(${pk2dump_STAT_SRCS})
add_library(pk2dump STATIC ${pk2dump_STAT_SRCS})

#message("C_FLAGS is ${C_FLAGS}")

