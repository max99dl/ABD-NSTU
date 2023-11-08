cmake_minimum_required(VERSION 3.15)

project(Socket_lib)

add_library(Sockets STATIC src/Sockets.cpp src/Sockets.hpp)
set_target_properties(
	Sockets PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)


