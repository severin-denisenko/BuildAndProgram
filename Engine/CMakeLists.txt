cmake_minimum_required(VERSION 3.22)
project(BAPEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter -Wno-c++11-narrowing")

add_subdirectory(deps/raylib)
include_directories(deps/raylib/src)

include_directories(include)

include_directories(deps/SLib/include)

file(GLOB SRC src/* src/*/*)
file(GLOB INCLUDE include/* include/*/*)
add_library(BAPEngine ${SRC} ${INCLUDE})
target_link_libraries(BAPEngine raylib)

file(GLOB TILE_EDITOR_SRC tools/TileEditor/*)
add_executable(TileEditor ${TILE_EDITOR_SRC})
target_include_directories(TileEditor PRIVATE tools/deps/raygui/src)
target_link_libraries(TileEditor raylib)
