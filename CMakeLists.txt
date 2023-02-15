cmake_minimum_required(VERSION 3.22)
project(BuildAndProgramm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_subdirectory(Engine)
include_directories(Engine/include)

file(GLOB SRC src/*)
add_executable(BuildAndProgramm ${SRC})
target_link_libraries(BuildAndProgramm BAPEngine)
