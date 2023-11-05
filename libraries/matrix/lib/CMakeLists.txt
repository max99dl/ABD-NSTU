cmake_minimum_required(VERSION 3.15)

project(Matrix VERSION 0.0.8)

set(
	SOURCES
	matrix.cpp
)

set(
	HEADERS
	matrix.h
)

add_library(matrix_lib STATIC ${SOURCES} ${HEADERS})
set_target_properties(
	matrix_lib PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

