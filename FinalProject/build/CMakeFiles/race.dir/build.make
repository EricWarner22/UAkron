# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ericwarner22/UAkron/FinalProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ericwarner22/UAkron/FinalProject/build

# Include any dependencies generated for this target.
include CMakeFiles/race.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/race.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/race.dir/flags.make

CMakeFiles/race.dir/main.cpp.o: CMakeFiles/race.dir/flags.make
CMakeFiles/race.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ericwarner22/UAkron/FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/race.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/race.dir/main.cpp.o -c /home/ericwarner22/UAkron/FinalProject/main.cpp

CMakeFiles/race.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/race.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ericwarner22/UAkron/FinalProject/main.cpp > CMakeFiles/race.dir/main.cpp.i

CMakeFiles/race.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/race.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ericwarner22/UAkron/FinalProject/main.cpp -o CMakeFiles/race.dir/main.cpp.s

CMakeFiles/race.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/race.dir/main.cpp.o.requires

CMakeFiles/race.dir/main.cpp.o.provides: CMakeFiles/race.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/race.dir/build.make CMakeFiles/race.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/race.dir/main.cpp.o.provides

CMakeFiles/race.dir/main.cpp.o.provides.build: CMakeFiles/race.dir/main.cpp.o


# Object files for target race
race_OBJECTS = \
"CMakeFiles/race.dir/main.cpp.o"

# External object files for target race
race_EXTERNAL_OBJECTS =

race: CMakeFiles/race.dir/main.cpp.o
race: CMakeFiles/race.dir/build.make
race: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
race: /usr/lib/x86_64-linux-gnu/libsfml-window.so
race: /usr/lib/x86_64-linux-gnu/libsfml-system.so
race: CMakeFiles/race.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ericwarner22/UAkron/FinalProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable race"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/race.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/race.dir/build: race

.PHONY : CMakeFiles/race.dir/build

CMakeFiles/race.dir/requires: CMakeFiles/race.dir/main.cpp.o.requires

.PHONY : CMakeFiles/race.dir/requires

CMakeFiles/race.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/race.dir/cmake_clean.cmake
.PHONY : CMakeFiles/race.dir/clean

CMakeFiles/race.dir/depend:
	cd /home/ericwarner22/UAkron/FinalProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ericwarner22/UAkron/FinalProject /home/ericwarner22/UAkron/FinalProject /home/ericwarner22/UAkron/FinalProject/build /home/ericwarner22/UAkron/FinalProject/build /home/ericwarner22/UAkron/FinalProject/build/CMakeFiles/race.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/race.dir/depend

