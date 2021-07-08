cmake_minimum_required(VERSION 3.16)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

project(tests)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

add_subdirectory(./googletest)

include(GoogleTest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
 
add_executable(UnitTests ${SRC_FILES})

target_link_libraries(UnitTests gtest gtest_main)

gtest_discover_tests(UnitTests)