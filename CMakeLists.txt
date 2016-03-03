cmake_minimum_required(VERSION 2.8)
find_program(CMAKE_C_COMPILER   NAMES clang)
find_program(CMAKE_CXX_COMPILER NAMES clang++)
find_program(CMAKE_LINKER       NAMES llvm-ld)
find_program(CMAKE_RANLIB       NAMES llvm-ranlib)
find_program(CMAKE_AR           NAMES llvm-ar)
add_definitions("-Wall -std=c++1y")

add_executable(main
    main.cpp
    Field.cpp
)
