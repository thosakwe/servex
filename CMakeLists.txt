cmake_minimum_required(VERSION 3.0)
project(servex)
set(CMAKE_CXX_STANDARD 11)
include_directories(src)
add_subdirectory(src)
add_subdirectory(example)
install(DIRECTORY src DESTINATION include PATTERN "*.h")