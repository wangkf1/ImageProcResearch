# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kevin/BeanImageProc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kevin/BeanImageProc

# Include any dependencies generated for this target.
include CMakeFiles/attempt4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/attempt4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/attempt4.dir/flags.make

CMakeFiles/attempt4.dir/attempt4.cpp.o: CMakeFiles/attempt4.dir/flags.make
CMakeFiles/attempt4.dir/attempt4.cpp.o: attempt4.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kevin/BeanImageProc/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/attempt4.dir/attempt4.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/attempt4.dir/attempt4.cpp.o -c /home/kevin/BeanImageProc/attempt4.cpp

CMakeFiles/attempt4.dir/attempt4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/attempt4.dir/attempt4.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kevin/BeanImageProc/attempt4.cpp > CMakeFiles/attempt4.dir/attempt4.cpp.i

CMakeFiles/attempt4.dir/attempt4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/attempt4.dir/attempt4.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kevin/BeanImageProc/attempt4.cpp -o CMakeFiles/attempt4.dir/attempt4.cpp.s

CMakeFiles/attempt4.dir/attempt4.cpp.o.requires:
.PHONY : CMakeFiles/attempt4.dir/attempt4.cpp.o.requires

CMakeFiles/attempt4.dir/attempt4.cpp.o.provides: CMakeFiles/attempt4.dir/attempt4.cpp.o.requires
	$(MAKE) -f CMakeFiles/attempt4.dir/build.make CMakeFiles/attempt4.dir/attempt4.cpp.o.provides.build
.PHONY : CMakeFiles/attempt4.dir/attempt4.cpp.o.provides

CMakeFiles/attempt4.dir/attempt4.cpp.o.provides.build: CMakeFiles/attempt4.dir/attempt4.cpp.o

# Object files for target attempt4
attempt4_OBJECTS = \
"CMakeFiles/attempt4.dir/attempt4.cpp.o"

# External object files for target attempt4
attempt4_EXTERNAL_OBJECTS =

attempt4: CMakeFiles/attempt4.dir/attempt4.cpp.o
attempt4: CMakeFiles/attempt4.dir/build.make
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
attempt4: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
attempt4: CMakeFiles/attempt4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable attempt4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/attempt4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/attempt4.dir/build: attempt4
.PHONY : CMakeFiles/attempt4.dir/build

CMakeFiles/attempt4.dir/requires: CMakeFiles/attempt4.dir/attempt4.cpp.o.requires
.PHONY : CMakeFiles/attempt4.dir/requires

CMakeFiles/attempt4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/attempt4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/attempt4.dir/clean

CMakeFiles/attempt4.dir/depend:
	cd /home/kevin/BeanImageProc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kevin/BeanImageProc /home/kevin/BeanImageProc /home/kevin/BeanImageProc /home/kevin/BeanImageProc /home/kevin/BeanImageProc/CMakeFiles/attempt4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/attempt4.dir/depend

