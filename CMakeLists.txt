cmake_minimum_required(VERSION 3.5.0)

PROJECT (TetGrain CXX)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Adaptor options
option(USE_CGAL "USE CGAL MESHER" OFF)


# Include sources
set(SOURCE_EXE
    src/grainmesh.h
    src/grainmesh.cpp
    src/iotetgen.h
    src/iotetgen.cpp
    src/common.h
    src/common.cpp
    src/main.cpp)

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



# Create executable file
add_executable(TetGrain ${SOURCE_EXE} ${SOURCE_NETGEN} ${SOURCE_CGAL})

if(USE_CGAL)
	target_link_libraries(TetGrain ${CGAL_LIBS})
endif()