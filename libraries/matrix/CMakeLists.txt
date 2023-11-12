cmake_minimum_required(VERSION 3.15)

project(Matrix_library)


add_library(matrix_lib STATIC src/matrix.cpp src/matrix.h)
set_target_properties(
	matrix_lib PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)


install(
	TARGETS matrix_lib EXPORT matrix_libTargets
	LIBRARY DESTINATION lib
	#ARCHIVE for static libraries
	ARCHIVE DESTINATION lib
	INCLUDES DESTINATION include
	
)
#cmake know all about target(matrix_lib) we do not need to add it in folder manually,
#but it is necessary for *.h files
install(FILES src/matrix.h DESTINATION include)

#next, install is used to be able use find_package() in other cmake lists
install(
	EXPORT matrix_libTargets
	FILE matrix_libConfig.cmake
	DESTINATION lib/cmake
)
