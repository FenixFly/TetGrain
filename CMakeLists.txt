cmake_minimum_required(VERSION 3.5.0)

PROJECT (TetGrain CXX)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Include sources
set(SOURCE_EXE
    src/main.cpp)


# Create executable file
add_executable(TetGrain ${SOURCE_EXE})