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
CMAKE_SOURCE_DIR = /home/oakenbow/Dev/Projects/CSCI-1107-Projects

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oakenbow/Dev/Projects/CSCI-1107-Projects/build

# Include any dependencies generated for this target.
include CMakeFiles/Lab-8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab-8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab-8.dir/flags.make

CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o: CMakeFiles/Lab-8.dir/flags.make
CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o: ../Source/Lab-8/LinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oakenbow/Dev/Projects/CSCI-1107-Projects/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o -c /home/oakenbow/Dev/Projects/CSCI-1107-Projects/Source/Lab-8/LinkedList.cpp

CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oakenbow/Dev/Projects/CSCI-1107-Projects/Source/Lab-8/LinkedList.cpp > CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.i

CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oakenbow/Dev/Projects/CSCI-1107-Projects/Source/Lab-8/LinkedList.cpp -o CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.s

CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o.requires:

.PHONY : CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o.requires

CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o.provides: CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab-8.dir/build.make CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o.provides.build
.PHONY : CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o.provides

CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o.provides.build: CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o


CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o: CMakeFiles/Lab-8.dir/flags.make
CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o: ../Source/Lab-8/linktester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oakenbow/Dev/Projects/CSCI-1107-Projects/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o -c /home/oakenbow/Dev/Projects/CSCI-1107-Projects/Source/Lab-8/linktester.cpp

CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oakenbow/Dev/Projects/CSCI-1107-Projects/Source/Lab-8/linktester.cpp > CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.i

CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oakenbow/Dev/Projects/CSCI-1107-Projects/Source/Lab-8/linktester.cpp -o CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.s

CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o.requires:

.PHONY : CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o.requires

CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o.provides: CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab-8.dir/build.make CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o.provides.build
.PHONY : CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o.provides

CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o.provides.build: CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o


# Object files for target Lab-8
Lab__8_OBJECTS = \
"CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o" \
"CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o"

# External object files for target Lab-8
Lab__8_EXTERNAL_OBJECTS =

Lab-8: CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o
Lab-8: CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o
Lab-8: CMakeFiles/Lab-8.dir/build.make
Lab-8: CMakeFiles/Lab-8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oakenbow/Dev/Projects/CSCI-1107-Projects/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab-8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab-8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab-8.dir/build: Lab-8

.PHONY : CMakeFiles/Lab-8.dir/build

CMakeFiles/Lab-8.dir/requires: CMakeFiles/Lab-8.dir/Source/Lab-8/LinkedList.cpp.o.requires
CMakeFiles/Lab-8.dir/requires: CMakeFiles/Lab-8.dir/Source/Lab-8/linktester.cpp.o.requires

.PHONY : CMakeFiles/Lab-8.dir/requires

CMakeFiles/Lab-8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab-8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab-8.dir/clean

CMakeFiles/Lab-8.dir/depend:
	cd /home/oakenbow/Dev/Projects/CSCI-1107-Projects/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oakenbow/Dev/Projects/CSCI-1107-Projects /home/oakenbow/Dev/Projects/CSCI-1107-Projects /home/oakenbow/Dev/Projects/CSCI-1107-Projects/build /home/oakenbow/Dev/Projects/CSCI-1107-Projects/build /home/oakenbow/Dev/Projects/CSCI-1107-Projects/build/CMakeFiles/Lab-8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab-8.dir/depend

