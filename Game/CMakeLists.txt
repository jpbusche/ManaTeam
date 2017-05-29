cmake_minimum_required(VERSION 3.0.2)
project(7keys LANGUAGES CXX)

# Set directory folders

set (PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set (PROJECT_SRC_DIR     "${PROJECT_SOURCE_DIR}/src")
set (PROJECT_ASSETS_DIR  "${PROJECT_SOURCE_DIR}/res")

file(GLOB_RECURSE SOURCES "${PROJECT_SRC_DIR}/*.cpp")

# Include Headers

include_directories("${PROJECT_INCLUDE_DIR}")

# Add Engine

set (PROJECT_ENGINE_DIR "${PROJECT_SOURCE_DIR}/engine")
add_subdirectory(${PROJECT_ENGINE_DIR})
include_directories(${ENGINE_INCLUDE_DIR})

# Compilation Flags

set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++11 -W -Wall -pedantic -std=c++11 -Wshadow -O2 -g")

# Executable

add_executable(7keys ${SOURCES})
target_link_libraries(7keys
					  engine
					  SDL2 SDL2_image SDL2_ttf SDL2_mixer)