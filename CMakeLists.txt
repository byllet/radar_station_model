cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME radar_station_model)
project(${PROJECT_NAME} LANGUAGES CXX)

file(GLOB_RECURSE source_list "src/*.cpp" "src/*.hpp")

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${source_list} ${SOURCES})
