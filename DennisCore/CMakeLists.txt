# ==================[Copyright Aarik R. 2023]==================
# Purpose : DennisCore CMake script
#
#
# =============================================================

cmake_minimum_required(VERSION 3.2)

project(DennisCore)

add_executable(DennisCore WIN32
	app.cpp
	app.h
	dennis.cpp
	dennis.h
	dennis_utils.cpp
	dennis_utils.h
	interface.h
	main.cpp
)

target_link_libraries(DennisCore dtspeak)

set_target_properties( DennisCore
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${DENNIS_BIN}"
	LIBRARY_OUTPUT_DIRECTORY_DEBUG "${DENNIS_BIN}"
	LIBRARY_OUTPUT_DIRECTORY_RELEASE "${DENNIS_BIN}"
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${DENNIS_BIN}"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${DENNIS_BIN}"
)

