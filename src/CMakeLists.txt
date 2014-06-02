include_directories(${Genetic_Alg_Lib_Cpp_SOURCE_DIR}/include)

add_library(Genetic_Alg_Lib_Cpp SHARED GenomaProc.cpp GA_Crossover.cpp GA_Mutation.cpp)
