cmake_minimum_required(VERSION 3.2)

project(Dennis)

link_directories(./lib)

# Common directories
set(DENNIS_ROOT ${CMAKE_SOURCE_DIR})
set(DENNIS_LIB ${DENNIS_ROOT}/lib)
set(DENNIS_BIN ${DENNIS_ROOT}/bin)

add_subdirectory(DennisCore)
add_subdirectory(DennisInstaller)
add_subdirectory(DennisWatch)
