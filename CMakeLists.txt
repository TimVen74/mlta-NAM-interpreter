cmake_minimum_required(VERSION 3.24)
project(NAM-interpreter CXX)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_OSX_ARCHITECTURES "arm64")

add_executable(main src/main.cpp)

#list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
find_package(GTest REQUIRED)
add_executable(tests tests/test.cpp)
target_link_libraries(tests
        GTest::GTest
        GTest::Main
)
