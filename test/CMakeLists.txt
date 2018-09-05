add_subdirectory(googletest)
include_directories(googletest/include)

include_directories(../code ../offer)

add_executable(_test test.cpp test4.cpp)
target_link_libraries(_test gtest LEETCODE OFFER)

include_directories(../algorithm)
add_executable(_test2 test2.cpp)
target_link_libraries(_test2 gtest ALGORITHM)

include_directories(../interview)
add_executable(_test3 test3.cpp)
target_link_libraries(_test3 INTERVIEW gtest)

include_directories(../huawei)
add_executable(_test4 test4.cpp)
target_link_libraries(_test4 HUAWEI gtest)

