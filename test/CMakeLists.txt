project(tests)
enable_testing()

include_directories(../src)

set(test1_source test1.cpp)
add_executable(test1 ${test1_source})
target_link_libraries(test1 TetGrain)

set(test2_source test2.cpp)
add_executable(test2 ${test2_source})
target_link_libraries(test2 TetGrain)

set(test3_source test3.cpp)
add_executable(test3 ${test3_source})
target_link_libraries(test3 TetGrain)

if(USE_CGAL)
	set(testcgal1_source testcgal1.cpp)
	add_executable(testcgal1 ${testcgal1_source})
	target_link_libraries(testcgal1 ${TetGrain})
endif()

add_test(NAME Test1 COMMAND test1)
