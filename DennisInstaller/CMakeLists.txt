# ==================[Copyright Aarik R. 2023]==================
# Purpose : DennisInstaller CMake script
#
#
# =============================================================

cmake_minimum_required(VERSION 3.2)

project(DennisInstaller)

add_executable(DennisInstaller WIN32
	main.cpp
	
	# Resources
	dennis.ico
	resource.h
	dennis.rc
	
)

set_target_properties( DennisInstaller
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${DENNIS_BIN}"
	LIBRARY_OUTPUT_DIRECTORY_DEBUG "${DENNIS_BIN}"
	LIBRARY_OUTPUT_DIRECTORY_RELEASE "${DENNIS_BIN}"
	RUNTIME_OUTPUT_DIRECTORY_DEBUG "${DENNIS_BIN}"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${DENNIS_BIN}"
)

