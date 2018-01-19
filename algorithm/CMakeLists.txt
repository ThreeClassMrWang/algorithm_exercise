cmake_minimum_required(VERSION 3.0)

set(ALGORITHM_FILES version.cpp version.hpp SortUtil.hpp 1_2sum.hpp 2_select_sort.hpp 3_insert_sort.hpp
        4_shell_sort.hpp 5_merge_sort.hpp 6_merge_sort_iter.hpp 7_quick_sort.hpp 8_quick_sort_iter.hpp 9_quick_sort_3way.hpp 11_MaxPQ.hpp 10_heap_sort.hpp)
add_library(ALGORITHM ${ALGORITHM_FILES})