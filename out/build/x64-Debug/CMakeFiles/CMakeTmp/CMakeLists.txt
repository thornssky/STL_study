cmake_minimum_required(VERSION 3.20.21032501.0)
cmake_policy(SET CMP0091 NEW)
project(CMAKE_TRY_COMPILE C)
set_property(DIRECTORY PROPERTY INCLUDE_DIRECTORIES "")
set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_C_FLAGS "/DWIN32 /D_WINDOWS")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILE_DEFINITIONS}")
set(CMAKE_C_FLAGS_DEBUG "/Zi /Ob0 /Od /RTC1")
set(CMAKE_EXE_LINKER_FLAGS "/machine:x64")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${EXE_LINKER_FLAGS}")
include_directories(${INCLUDE_DIRECTORIES})
set(CMAKE_SUPPRESS_REGENERATION 1)
link_directories(${LINK_DIRECTORIES})
cmake_policy(SET CMP0065 NEW)
cmake_policy(SET CMP0083 NEW)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/Users/throns/Desktop/STL_study/out/build/x64-Debug/CMakeFiles/CMakeTmp")
add_executable(cmTC_da32e "D:/Program Files (x86)/Microsoft Visual Studio/2019/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/share/cmake-3.20/Modules/CMakeCCompilerABI.c")
target_link_libraries(cmTC_da32e ${LINK_LIBRARIES})
