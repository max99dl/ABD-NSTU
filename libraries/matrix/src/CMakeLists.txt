cmake_minimum_required(VERSION 3.15)

project(Main VERSION 0.0.9)

add_executable(main main.cpp)
set_target_properties(
	main PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

target_include_directories(
	main
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
target_link_libraries(main matrix_lib)
