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
include CMakeFiles/Throughput_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Throughput_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Throughput_test.dir/flags.make

CMakeFiles/Throughput_test.dir/Troughput_test.cpp.o: CMakeFiles/Throughput_test.dir/flags.make
CMakeFiles/Throughput_test.dir/Troughput_test.cpp.o: ../Troughput_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/documents/comm_test/testC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Throughput_test.dir/Troughput_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Throughput_test.dir/Troughput_test.cpp.o -c /home/pi/documents/comm_test/testC/Troughput_test.cpp

CMakeFiles/Throughput_test.dir/Troughput_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Throughput_test.dir/Troughput_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/documents/comm_test/testC/Troughput_test.cpp > CMakeFiles/Throughput_test.dir/Troughput_test.cpp.i

CMakeFiles/Throughput_test.dir/Troughput_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Throughput_test.dir/Troughput_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/documents/comm_test/testC/Troughput_test.cpp -o CMakeFiles/Throughput_test.dir/Troughput_test.cpp.s

# Object files for target Throughput_test
Throughput_test_OBJECTS = \
"CMakeFiles/Throughput_test.dir/Troughput_test.cpp.o"

# External object files for target Throughput_test
Throughput_test_EXTERNAL_OBJECTS =

Throughput_test: CMakeFiles/Throughput_test.dir/Troughput_test.cpp.o
Throughput_test: CMakeFiles/Throughput_test.dir/build.make
Throughput_test: CMakeFiles/Throughput_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/documents/comm_test/testC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Throughput_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Throughput_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Throughput_test.dir/build: Throughput_test

.PHONY : CMakeFiles/Throughput_test.dir/build

CMakeFiles/Throughput_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Throughput_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Throughput_test.dir/clean

CMakeFiles/Throughput_test.dir/depend:
	cd /home/pi/documents/comm_test/testC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/documents/comm_test/testC /home/pi/documents/comm_test/testC /home/pi/documents/comm_test/testC/build /home/pi/documents/comm_test/testC/build /home/pi/documents/comm_test/testC/build/CMakeFiles/Throughput_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Throughput_test.dir/depend
