# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ShowChar1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ShowChar1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ShowChar1.dir/flags.make

CMakeFiles/ShowChar1.dir/main.c.obj: CMakeFiles/ShowChar1.dir/flags.make
CMakeFiles/ShowChar1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ShowChar1.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ShowChar1.dir\main.c.obj   -c C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1\main.c

CMakeFiles/ShowChar1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ShowChar1.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1\main.c > CMakeFiles\ShowChar1.dir\main.c.i

CMakeFiles/ShowChar1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ShowChar1.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1\main.c -o CMakeFiles\ShowChar1.dir\main.c.s

CMakeFiles/ShowChar1.dir/main.c.obj.requires:

.PHONY : CMakeFiles/ShowChar1.dir/main.c.obj.requires

CMakeFiles/ShowChar1.dir/main.c.obj.provides: CMakeFiles/ShowChar1.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\ShowChar1.dir\build.make CMakeFiles/ShowChar1.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/ShowChar1.dir/main.c.obj.provides

CMakeFiles/ShowChar1.dir/main.c.obj.provides.build: CMakeFiles/ShowChar1.dir/main.c.obj


# Object files for target ShowChar1
ShowChar1_OBJECTS = \
"CMakeFiles/ShowChar1.dir/main.c.obj"

# External object files for target ShowChar1
ShowChar1_EXTERNAL_OBJECTS =

ShowChar1.exe: CMakeFiles/ShowChar1.dir/main.c.obj
ShowChar1.exe: CMakeFiles/ShowChar1.dir/build.make
ShowChar1.exe: CMakeFiles/ShowChar1.dir/linklibs.rsp
ShowChar1.exe: CMakeFiles/ShowChar1.dir/objects1.rsp
ShowChar1.exe: CMakeFiles/ShowChar1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ShowChar1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ShowChar1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ShowChar1.dir/build: ShowChar1.exe

.PHONY : CMakeFiles/ShowChar1.dir/build

CMakeFiles/ShowChar1.dir/requires: CMakeFiles/ShowChar1.dir/main.c.obj.requires

.PHONY : CMakeFiles/ShowChar1.dir/requires

CMakeFiles/ShowChar1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ShowChar1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ShowChar1.dir/clean

CMakeFiles/ShowChar1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1 C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1 C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1\cmake-build-debug C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1\cmake-build-debug C:\Users\HZWNB147\CLionProjects\CandCPlusplusDemo\CPrimer\ShowChar1\cmake-build-debug\CMakeFiles\ShowChar1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ShowChar1.dir/depend
