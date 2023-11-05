# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maxim/git/ABD-NSTU/libraries/matrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maxim/git/ABD-NSTU/libraries/matrix/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/matrix_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/matrix_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/matrix_lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/matrix_lib.dir/flags.make

lib/CMakeFiles/matrix_lib.dir/matrix.cpp.o: lib/CMakeFiles/matrix_lib.dir/flags.make
lib/CMakeFiles/matrix_lib.dir/matrix.cpp.o: ../lib/matrix.cpp
lib/CMakeFiles/matrix_lib.dir/matrix.cpp.o: lib/CMakeFiles/matrix_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxim/git/ABD-NSTU/libraries/matrix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/matrix_lib.dir/matrix.cpp.o"
	cd /home/maxim/git/ABD-NSTU/libraries/matrix/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/matrix_lib.dir/matrix.cpp.o -MF CMakeFiles/matrix_lib.dir/matrix.cpp.o.d -o CMakeFiles/matrix_lib.dir/matrix.cpp.o -c /home/maxim/git/ABD-NSTU/libraries/matrix/lib/matrix.cpp

lib/CMakeFiles/matrix_lib.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matrix_lib.dir/matrix.cpp.i"
	cd /home/maxim/git/ABD-NSTU/libraries/matrix/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxim/git/ABD-NSTU/libraries/matrix/lib/matrix.cpp > CMakeFiles/matrix_lib.dir/matrix.cpp.i

lib/CMakeFiles/matrix_lib.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matrix_lib.dir/matrix.cpp.s"
	cd /home/maxim/git/ABD-NSTU/libraries/matrix/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxim/git/ABD-NSTU/libraries/matrix/lib/matrix.cpp -o CMakeFiles/matrix_lib.dir/matrix.cpp.s

# Object files for target matrix_lib
matrix_lib_OBJECTS = \
"CMakeFiles/matrix_lib.dir/matrix.cpp.o"

# External object files for target matrix_lib
matrix_lib_EXTERNAL_OBJECTS =

lib/libmatrix_lib.a: lib/CMakeFiles/matrix_lib.dir/matrix.cpp.o
lib/libmatrix_lib.a: lib/CMakeFiles/matrix_lib.dir/build.make
lib/libmatrix_lib.a: lib/CMakeFiles/matrix_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maxim/git/ABD-NSTU/libraries/matrix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmatrix_lib.a"
	cd /home/maxim/git/ABD-NSTU/libraries/matrix/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/matrix_lib.dir/cmake_clean_target.cmake
	cd /home/maxim/git/ABD-NSTU/libraries/matrix/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrix_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/matrix_lib.dir/build: lib/libmatrix_lib.a
.PHONY : lib/CMakeFiles/matrix_lib.dir/build

lib/CMakeFiles/matrix_lib.dir/clean:
	cd /home/maxim/git/ABD-NSTU/libraries/matrix/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/matrix_lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/matrix_lib.dir/clean

lib/CMakeFiles/matrix_lib.dir/depend:
	cd /home/maxim/git/ABD-NSTU/libraries/matrix/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maxim/git/ABD-NSTU/libraries/matrix /home/maxim/git/ABD-NSTU/libraries/matrix/lib /home/maxim/git/ABD-NSTU/libraries/matrix/build /home/maxim/git/ABD-NSTU/libraries/matrix/build/lib /home/maxim/git/ABD-NSTU/libraries/matrix/build/lib/CMakeFiles/matrix_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/matrix_lib.dir/depend

