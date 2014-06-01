cmake_minimum_required (VERSION 2.6)
project (Genetic_Alg_Lib_Cpp) 

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${Genetic_Alg_Lib_Cpp_SOURCE_DIR}/lib)

add_subdirectory(src)

add_subdirectory(include)

add_subdirectory(test)

