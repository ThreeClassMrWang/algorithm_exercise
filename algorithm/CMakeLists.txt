cmake_minimum_required(VERSION 3.0)

set(ALGORITHM_FILES version.cpp version.hpp SortUtil.hpp 1_2sum.hpp 2_select_sort.hpp 3_insert_sort.hpp
        4_shell_sort.hpp 5_merge_sort.hpp 6_merge_sort_iter.hpp 7_quick_sort.hpp 8_quick_sort_iter.hpp 9_quick_sort_3way.hpp 11_MaxPQ.hpp 10_heap_sort.hpp 12_find_repeat_element.hpp 13_kandall_distance.hpp 14_select_k.hpp 15_binary_search.hpp 16_binary_search_tree.hpp 17_gnu_hash.hpp 18_string_simple_search.hpp 19_kmp.hpp 20_horspool.hpp)
add_library(ALGORITHM ${ALGORITHM_FILES})