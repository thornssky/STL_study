cmake_minimum_required(VERSION 3.16.3)

project(STLSTUDY)

include_directories(include)
# 调用的头文件

add_executable(stl_itextend_exe main.cpp src/stl_iterator.cpp src/stl_array.cpp
 src/stl_vector.cpp src/stl_deque.cpp src/stl_list.cpp src/stl_map.cpp src/stl_set 
 src/stl_unordered_map.cpp src/stl_unordered_set.cpp src/stl_adapter.cpp src/stl_iterator_extend.cpp
 )
# 生成可执行文件

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -o2 -Wall")