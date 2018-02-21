cmake_minimum_required(VERSION 3.5.0)

PROJECT (TetGrain CXX)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Static / dynamic library
option(BUILD_STATIC "BUILD STATIC LIBRARY" OFF) 

# Testing options
option(USE_TESTS "ENABLE TESTS" OFF)

# Adaptor options
option(USE_CGAL "USE CGAL MESHER" OFF)

# Include sources
set(SOURCE_EXE
    src/grainmesh.h
    src/grainmesh.cpp
    src/iotetgen.h
    src/iotetgen.cpp
    src/common.h
    src/common.cpp)

set(SOURCE_NETGEN
	src/netgenadaptor.h
	src/netgenadaptor.cpp)

SET(SOURCE_CGAL)
if(USE_CGAL)
	find_package(CGAL)
	include(${CGAL_USE_FILE})
	SET(SOURCE_CGAL
		src/adaptorcgal.h
		src/adaptorcgal.cpp)
endif()

# Create library
if(BUILD_STATIC)
	add_library(TetGrain ${SOURCE_EXE} ${SOURCE_NETGEN} ${SOURCE_CGAL})
else()
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
	add_library(TetGrain SHARED ${SOURCE_EXE} ${SOURCE_NETGEN} ${SOURCE_CGAL})
endif()


if(USE_TESTS)
	add_subdirectory(test build/test)
endif()

if(USE_CGAL)
	target_link_libraries(TetGrain ${CGAL_LIBS})
endif()

