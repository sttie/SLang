# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/samvelochka/Рабочий стол/Проекты/lang2.0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lang2_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lang2_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lang2_0.dir/flags.make

CMakeFiles/lang2_0.dir/src/main.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lang2_0.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/main.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/main.cpp"

CMakeFiles/lang2_0.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/main.cpp" > CMakeFiles/lang2_0.dir/src/main.cpp.i

CMakeFiles/lang2_0.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/main.cpp" -o CMakeFiles/lang2_0.dir/src/main.cpp.s

CMakeFiles/lang2_0.dir/src/parse.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/parse.cpp.o: ../src/parse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lang2_0.dir/src/parse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/parse.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/parse.cpp"

CMakeFiles/lang2_0.dir/src/parse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/parse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/parse.cpp" > CMakeFiles/lang2_0.dir/src/parse.cpp.i

CMakeFiles/lang2_0.dir/src/parse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/parse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/parse.cpp" -o CMakeFiles/lang2_0.dir/src/parse.cpp.s

CMakeFiles/lang2_0.dir/src/ast.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast.cpp.o: ../src/ast.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lang2_0.dir/src/ast.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast.cpp"

CMakeFiles/lang2_0.dir/src/ast.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast.cpp" > CMakeFiles/lang2_0.dir/src/ast.cpp.i

CMakeFiles/lang2_0.dir/src/ast.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast.cpp" -o CMakeFiles/lang2_0.dir/src/ast.cpp.s

CMakeFiles/lang2_0.dir/src/lexer.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/lexer.cpp.o: ../src/lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lang2_0.dir/src/lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/lexer.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/lexer.cpp"

CMakeFiles/lang2_0.dir/src/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/lexer.cpp" > CMakeFiles/lang2_0.dir/src/lexer.cpp.i

CMakeFiles/lang2_0.dir/src/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/lexer.cpp" -o CMakeFiles/lang2_0.dir/src/lexer.cpp.s

CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.o: ../src/ast_types/ASTAssignment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTAssignment.cpp"

CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTAssignment.cpp" > CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.i

CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTAssignment.cpp" -o CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.s

CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.o: ../src/ast_types/ASTFunction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTFunction.cpp"

CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTFunction.cpp" > CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.i

CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTFunction.cpp" -o CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.s

CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.o: ../src/ast_types/ASTIf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTIf.cpp"

CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTIf.cpp" > CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.i

CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTIf.cpp" -o CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.s

CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.o: ../src/ast_types/ASTOperation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTOperation.cpp"

CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTOperation.cpp" > CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.i

CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTOperation.cpp" -o CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.s

CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.o: ../src/ast_types/ASTPrint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTPrint.cpp"

CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTPrint.cpp" > CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.i

CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTPrint.cpp" -o CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.s

CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.o: ../src/ast_types/ASTReturn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTReturn.cpp"

CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTReturn.cpp" > CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.i

CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTReturn.cpp" -o CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.s

CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.o: ../src/ast_types/ASTVariable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTVariable.cpp"

CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTVariable.cpp" > CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.i

CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTVariable.cpp" -o CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.s

CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.o: ../src/ast_types/ASTWhile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTWhile.cpp"

CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTWhile.cpp" > CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.i

CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTWhile.cpp" -o CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.s

CMakeFiles/lang2_0.dir/src/type.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/type.cpp.o: ../src/type.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/lang2_0.dir/src/type.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/type.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/type.cpp"

CMakeFiles/lang2_0.dir/src/type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/type.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/type.cpp" > CMakeFiles/lang2_0.dir/src/type.cpp.i

CMakeFiles/lang2_0.dir/src/type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/type.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/type.cpp" -o CMakeFiles/lang2_0.dir/src/type.cpp.s

CMakeFiles/lang2_0.dir/src/symtable.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/symtable.cpp.o: ../src/symtable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/lang2_0.dir/src/symtable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/symtable.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/symtable.cpp"

CMakeFiles/lang2_0.dir/src/symtable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/symtable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/symtable.cpp" > CMakeFiles/lang2_0.dir/src/symtable.cpp.i

CMakeFiles/lang2_0.dir/src/symtable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/symtable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/symtable.cpp" -o CMakeFiles/lang2_0.dir/src/symtable.cpp.s

CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.o: ../src/ast_types/ASTFunCall.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTFunCall.cpp"

CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTFunCall.cpp" > CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.i

CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/ast_types/ASTFunCall.cpp" -o CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.s

CMakeFiles/lang2_0.dir/src/token.cpp.o: CMakeFiles/lang2_0.dir/flags.make
CMakeFiles/lang2_0.dir/src/token.cpp.o: ../src/token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/lang2_0.dir/src/token.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lang2_0.dir/src/token.cpp.o -c "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/token.cpp"

CMakeFiles/lang2_0.dir/src/token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lang2_0.dir/src/token.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/token.cpp" > CMakeFiles/lang2_0.dir/src/token.cpp.i

CMakeFiles/lang2_0.dir/src/token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lang2_0.dir/src/token.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/samvelochka/Рабочий стол/Проекты/lang2.0/src/token.cpp" -o CMakeFiles/lang2_0.dir/src/token.cpp.s

# Object files for target lang2_0
lang2_0_OBJECTS = \
"CMakeFiles/lang2_0.dir/src/main.cpp.o" \
"CMakeFiles/lang2_0.dir/src/parse.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast.cpp.o" \
"CMakeFiles/lang2_0.dir/src/lexer.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.o" \
"CMakeFiles/lang2_0.dir/src/type.cpp.o" \
"CMakeFiles/lang2_0.dir/src/symtable.cpp.o" \
"CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.o" \
"CMakeFiles/lang2_0.dir/src/token.cpp.o"

# External object files for target lang2_0
lang2_0_EXTERNAL_OBJECTS =

lang2_0: CMakeFiles/lang2_0.dir/src/main.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/parse.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/lexer.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast_types/ASTAssignment.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast_types/ASTFunction.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast_types/ASTIf.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast_types/ASTOperation.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast_types/ASTPrint.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast_types/ASTReturn.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast_types/ASTVariable.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast_types/ASTWhile.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/type.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/symtable.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/ast_types/ASTFunCall.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/src/token.cpp.o
lang2_0: CMakeFiles/lang2_0.dir/build.make
lang2_0: CMakeFiles/lang2_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable lang2_0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lang2_0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lang2_0.dir/build: lang2_0

.PHONY : CMakeFiles/lang2_0.dir/build

CMakeFiles/lang2_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lang2_0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lang2_0.dir/clean

CMakeFiles/lang2_0.dir/depend:
	cd "/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/samvelochka/Рабочий стол/Проекты/lang2.0" "/home/samvelochka/Рабочий стол/Проекты/lang2.0" "/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug" "/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug" "/home/samvelochka/Рабочий стол/Проекты/lang2.0/cmake-build-debug/CMakeFiles/lang2_0.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lang2_0.dir/depend

