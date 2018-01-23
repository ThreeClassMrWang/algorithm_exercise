cmake_minimum_required(VERSION 3.0)

add_executable(1_recur_tree 1_recur_tree.cpp)
add_executable(2_serize_btree 2_serize_btree.cpp)
add_executable(3_morris_btree 3_morris_btree.cpp)
add_executable(4_max_sum_length 4_max_sum_length.cpp)
add_executable(5_find_max_searchtree 5_find_max_searchtree.cpp)
add_executable(6_min_path 6_min_path.cpp)

set(INTERVIEW_FILES interview.hpp interview.cpp 354_max_length.hpp 356_subarray_max_length.hpp 140_the_sample_structure.hpp 141_same_struct.hpp node.hpp 7_is_banlance_tree.hpp 8_fibonacci.hpp)
add_library(INTERVIEW ${INTERVIEW_FILES})