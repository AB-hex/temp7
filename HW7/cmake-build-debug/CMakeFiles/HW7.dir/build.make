# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/HW7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW7.dir/flags.make

CMakeFiles/HW7.dir/main.c.obj: CMakeFiles/HW7.dir/flags.make
CMakeFiles/HW7.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HW7.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HW7.dir\main.c.obj   -c "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\main.c"

CMakeFiles/HW7.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW7.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\main.c" > CMakeFiles\HW7.dir\main.c.i

CMakeFiles/HW7.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW7.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\main.c" -o CMakeFiles\HW7.dir\main.c.s

CMakeFiles/HW7.dir/grades.c.obj: CMakeFiles/HW7.dir/flags.make
CMakeFiles/HW7.dir/grades.c.obj: ../grades.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/HW7.dir/grades.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\HW7.dir\grades.c.obj   -c "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\grades.c"

CMakeFiles/HW7.dir/grades.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HW7.dir/grades.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\grades.c" > CMakeFiles\HW7.dir\grades.c.i

CMakeFiles/HW7.dir/grades.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HW7.dir/grades.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\grades.c" -o CMakeFiles\HW7.dir\grades.c.s

# Object files for target HW7
HW7_OBJECTS = \
"CMakeFiles/HW7.dir/main.c.obj" \
"CMakeFiles/HW7.dir/grades.c.obj"

# External object files for target HW7
HW7_EXTERNAL_OBJECTS =

HW7.exe: CMakeFiles/HW7.dir/main.c.obj
HW7.exe: CMakeFiles/HW7.dir/grades.c.obj
HW7.exe: CMakeFiles/HW7.dir/build.make
HW7.exe: CMakeFiles/HW7.dir/linklibs.rsp
HW7.exe: CMakeFiles/HW7.dir/objects1.rsp
HW7.exe: CMakeFiles/HW7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable HW7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HW7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW7.dir/build: HW7.exe

.PHONY : CMakeFiles/HW7.dir/build

CMakeFiles/HW7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HW7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HW7.dir/clean

CMakeFiles/HW7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7" "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7" "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\cmake-build-debug" "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\cmake-build-debug" "E:\HW Technion Studies\semester 9\mamat\HW7\temp7-main\HW7\cmake-build-debug\CMakeFiles\HW7.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/HW7.dir/depend

