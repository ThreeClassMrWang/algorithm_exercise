add_subdirectory(googletest)
include_directories(googletest/include)

include_directories(../code)

add_executable(_test test.cpp)
target_link_libraries(_test gtest LEETCODE)

