cmake_minimum_required(VERSION 2.8)
project(rlalgorithms)

set(CMAKE_VERBOSE_MAKEFILE off)
set(GTEST_PATH ${CMAKE_CURRENT_SOURCE_DIR}/deps/googletest/googletest)
set(GOOGLE_TEST_INCLUDE_PATH ${GTEST_PATH}/include)
set(TESTS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(UNIT_TESTS_PATH ${TESTS_PATH}/unit)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -pthread -std=c++11 -Wall -Werror")

# Unit tests
add_subdirectory(${GTEST_PATH})
enable_testing()
include_directories(
  ${GTEST_PATH}/include ${GTEST_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/lib
)
set(UNIT_TEST_FILES
  ${UNIT_TESTS_PATH}/binary_search.cpp
  ${UNIT_TESTS_PATH}/merge_sort.cpp
  ${UNIT_TESTS_PATH}/binary_heap.cpp
  ${UNIT_TESTS_PATH}/bst.cpp
  ${UNIT_TESTS_PATH}/largest_square_1s_matrix.cpp
)

add_executable(unit_tests ${UNIT_TEST_FILES})
target_link_libraries(unit_tests pthread)
target_link_libraries(unit_tests gtest gtest_main)
