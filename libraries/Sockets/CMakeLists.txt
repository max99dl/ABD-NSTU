cmake_minimum_required(VERSION 3.15)

project(Socket_lib)

add_library(Sockets_lib STATIC src/Sockets.cpp src/Sockets.hpp)
set_target_properties(
	Sockets_lib PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

install(
	TARGETS Sockets_lib
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	INCLUDES DESTINATION include
)
install(FILES src/Sockets.hpp DESTINATION include)


install(
	EXPORT Sockets_libTargets
	FILE Sockets_libConfig.config
	DESTINATION lib/cmake
)
