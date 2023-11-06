cmake_minimum_required(VERSION 3.15)

project(Server)


add_executable(server src/server.cpp)
set_target_properties(
	server PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(client src/client.cpp)
set_target_properties(
	client PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
