include_directories(${Genetic_Alg_Lib_Cpp_SOURCE_DIR}/include)
link_directories(${Genetic_Alg_Lib_Cpp_SOURCE_DIR}/lib)

add_executable(test test.cpp)

target_link_libraries(test Genetic_Alg_Lib_Cpp)

add_test(Test test)
