# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\GitCode\VscodeQt\src\ProjectGlory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\GitCode\VscodeQt\src\ProjectGlory\build

# Utility rule file for ZipTool_autogen.

# Include any custom commands dependencies for this target.
include subziptool/CMakeFiles/ZipTool_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include subziptool/CMakeFiles/ZipTool_autogen.dir/progress.make

subziptool/CMakeFiles/ZipTool_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=E:\GitCode\VscodeQt\src\ProjectGlory\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target ZipTool"
	cd /d E:\GitCode\VscodeQt\src\ProjectGlory\build\subziptool && "D:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen E:/GitCode/VscodeQt/src/ProjectGlory/build/subziptool/CMakeFiles/ZipTool_autogen.dir/AutogenInfo.json Debug

ZipTool_autogen: subziptool/CMakeFiles/ZipTool_autogen
ZipTool_autogen: subziptool/CMakeFiles/ZipTool_autogen.dir/build.make
.PHONY : ZipTool_autogen

# Rule to build all files generated by this target.
subziptool/CMakeFiles/ZipTool_autogen.dir/build: ZipTool_autogen
.PHONY : subziptool/CMakeFiles/ZipTool_autogen.dir/build

subziptool/CMakeFiles/ZipTool_autogen.dir/clean:
	cd /d E:\GitCode\VscodeQt\src\ProjectGlory\build\subziptool && $(CMAKE_COMMAND) -P CMakeFiles\ZipTool_autogen.dir\cmake_clean.cmake
.PHONY : subziptool/CMakeFiles/ZipTool_autogen.dir/clean

subziptool/CMakeFiles/ZipTool_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\GitCode\VscodeQt\src\ProjectGlory E:\GitCode\VscodeQt\src\ProjectGlory\subziptool E:\GitCode\VscodeQt\src\ProjectGlory\build E:\GitCode\VscodeQt\src\ProjectGlory\build\subziptool E:\GitCode\VscodeQt\src\ProjectGlory\build\subziptool\CMakeFiles\ZipTool_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : subziptool/CMakeFiles/ZipTool_autogen.dir/depend

