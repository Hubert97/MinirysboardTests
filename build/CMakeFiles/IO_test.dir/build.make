# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/documents/comm_test/testC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/documents/comm_test/testC/build

# Include any dependencies generated for this target.
include CMakeFiles/IO_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IO_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IO_test.dir/flags.make

CMakeFiles/IO_test.dir/IO_Test.cpp.o: CMakeFiles/IO_test.dir/flags.make
CMakeFiles/IO_test.dir/IO_Test.cpp.o: ../IO_Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/documents/comm_test/testC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IO_test.dir/IO_Test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IO_test.dir/IO_Test.cpp.o -c /home/pi/documents/comm_test/testC/IO_Test.cpp

CMakeFiles/IO_test.dir/IO_Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IO_test.dir/IO_Test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/documents/comm_test/testC/IO_Test.cpp > CMakeFiles/IO_test.dir/IO_Test.cpp.i

CMakeFiles/IO_test.dir/IO_Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IO_test.dir/IO_Test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/documents/comm_test/testC/IO_Test.cpp -o CMakeFiles/IO_test.dir/IO_Test.cpp.s

# Object files for target IO_test
IO_test_OBJECTS = \
"CMakeFiles/IO_test.dir/IO_Test.cpp.o"

# External object files for target IO_test
IO_test_EXTERNAL_OBJECTS =

IO_test: CMakeFiles/IO_test.dir/IO_Test.cpp.o
IO_test: CMakeFiles/IO_test.dir/build.make
IO_test: CMakeFiles/IO_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/documents/comm_test/testC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IO_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IO_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IO_test.dir/build: IO_test

.PHONY : CMakeFiles/IO_test.dir/build

CMakeFiles/IO_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IO_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IO_test.dir/clean

CMakeFiles/IO_test.dir/depend:
	cd /home/pi/documents/comm_test/testC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/documents/comm_test/testC /home/pi/documents/comm_test/testC /home/pi/documents/comm_test/testC/build /home/pi/documents/comm_test/testC/build /home/pi/documents/comm_test/testC/build/CMakeFiles/IO_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IO_test.dir/depend

