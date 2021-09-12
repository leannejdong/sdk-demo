cmake_minimum_required(VERSION 3.10)

add_compile_options(-std=c++17 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wunused -pedantic)
project(bot)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(
        bot
        main.cpp
)

target_link_libraries(bot ${CONAN_LIBS})