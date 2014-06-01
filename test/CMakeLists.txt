include_directories(${GraphLib_SOURCE_DIR}/include)
link_directories(${GraphLib_SOURCE_DIR}/lib)

add_executable(test1 test1.cpp)

add_executable(test2 test2.cpp)

target_link_libraries(test1 GraphLib)

target_link_libraries(test2 GraphLib)

add_test(Test test1)

add_test(Test test2)
