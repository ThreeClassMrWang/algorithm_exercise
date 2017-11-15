include_directories(../test/googletest/include)

set(FILES code.h code.cpp 1_two_sum.h 7_reverse_integer.h 9_palindrome_number.h 14_longest_common_prefix.h 20_valid_parentheses.h 21_merge_two_sorted_lists.h)
add_library(LEETCODE ${FILES})
