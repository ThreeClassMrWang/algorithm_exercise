include_directories(../test/googletest/include)

set(FILES code.h code.cpp 1_two_sum.h 7_reverse_integer.h 9_palindrome_number.h 14_longest_common_prefix.h
        20_valid_parentheses.h 21_merge_two_sorted_lists.h 26_remove_duplicates_from_sorted_array.h
        2_add_two_numbers.h 3_longest_substring_without_repeating_characters.h 5_longest_palindromic_substring.h
        6_zigzag_conversion.h 8_string_to_integer.h 11_container_with_most_water.h 12_integer_to_roman.h 15_3sum.h
        16_3sum_closest.h 17_letter_combinations_of_a_phone_number.h 18_4sum.h 226_invert_binary_tree.hpp 19_removed_nth_node_from_end_of_list.h 22_generate_parentneses.h ../offer/1_search_array.hpp ../offer/offer.cpp ../offer/offer.hpp)
add_library(LEETCODE ${FILES})
