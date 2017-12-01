//
// Created by wcj on 17-11-14.
//

#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "code.h"
#include "14_longest_common_prefix.h"
#include "20_valid_parentheses.h"
#include "21_merge_two_sorted_lists.h"
#include "26_remove_duplicates_from_sorted_array.h"
#include "2_add_two_numbers.h"
#include "3_longest_substring_without_repeating_characters.h"
#include "5_longest_palindromic_substring.h"
#include "6_zigzag_conversion.h"
#include "8_string_to_integer.h"
#include "11_container_with_most_water.h"
#include "12_integer_to_roman.h"
#include "15_3sum.h"
#include "16_3sum_closest.h"
#include "17_letter_combinations_of_a_phone_number.h"

TEST(_test, hello) {
    std::string s = "Hello GoogleTest!";
    EXPECT_EQ(s, "Hello GoogleTest!");
    std::cout << s << std::endl;
    std::cout << "Version of Leetcode is: " << leetcode::version() << std::endl;
}

TEST(longest_common_prefix, test) {
    std::vector<std::string> in;
    std::string res;

    in = {};
    res = leetcode::LongestCommonPrefix::longestCommonPrefix(in);
    EXPECT_EQ(res, "");

    in = {"a"};
    res = leetcode::LongestCommonPrefix::longestCommonPrefix(in);
    EXPECT_EQ(res, "a");

    in = {"a", "a"};
    res = leetcode::LongestCommonPrefix::longestCommonPrefix(in);
    EXPECT_EQ(res, "a");

    in = {"abc", "abc"};
    res = leetcode::LongestCommonPrefix::longestCommonPrefix(in);
    EXPECT_EQ(res, "abc");

    in = {"abc", "abcde"};
    res = leetcode::LongestCommonPrefix::longestCommonPrefix(in);
    EXPECT_EQ(res, "abc");

    in = {"abchug ", "abcde"};
    res = leetcode::LongestCommonPrefix::longestCommonPrefix(in);
    EXPECT_EQ(res, "abc");

    in = {"hudgs", "tffsc"};
    res = leetcode::LongestCommonPrefix::longestCommonPrefix(in);
    EXPECT_EQ(res, "");

    in = {"", "ggjs"};
    res = leetcode::LongestCommonPrefix::longestCommonPrefix(in);
    EXPECT_EQ(res, "");
}

TEST(valid_parentness, test) {
    std::string in;
    bool res;

    in = "[";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, false);

    in = ")";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, false);

    in = "()";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, true);

    in = ")(";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, false);

    in = "(((()))";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, false);

    in = "((())))";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, false);

    in = "(]";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, false);

    in = "([)]";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, false);

    in = "()[]{}";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, true);

    in = "([]){([])}";
    res = leetcode::ValidParentheses::isValid(in);
    EXPECT_EQ(res, true);
}

TEST(merge_two_sorted_lists, test) {
    typedef leetcode::MergeTwoSortedLists::ListNode ListNode;
    constexpr int N = 10;
    std::vector<ListNode *> vectors;
    for (int i = 0; i < N; i++)
        vectors.push_back(new ListNode(i));

    ListNode *l1, *l2, *res;

    l1 = nullptr;
    l2 = nullptr;
    res = leetcode::MergeTwoSortedLists::mergeTwoLists(l1, l2);
    EXPECT_EQ(nullptr, res);

    l1 = vectors[1];
    l2 = nullptr;
    res = leetcode::MergeTwoSortedLists::mergeTwoLists(l1, l2);
    EXPECT_EQ(1, res->val);

    l1 = vectors[2];
    l2 = vectors[1];
    res = leetcode::MergeTwoSortedLists::mergeTwoLists(l1, l2);
    EXPECT_EQ(1, res->val);
    EXPECT_EQ(2, res->next->val);

    l1 = vectors[2];
    l1->next = vectors[6];
    l2 = vectors[1];
    l2->next = vectors[3];
    l2->next->next = vectors[5];
    res = leetcode::MergeTwoSortedLists::mergeTwoLists(l1, l2);
    EXPECT_EQ(1, res->val);
    EXPECT_EQ(2, res->next->val);
    EXPECT_EQ(3, res->next->next->val);
    EXPECT_EQ(5, res->next->next->next->val);
    EXPECT_EQ(6, res->next->next->next->next->val);

    // Delete
    for (auto &node : vectors)
        delete node;
}

TEST(remove_duplicates_from_sorted_array, test) {
    std::vector<int> in;
    int res;

    in = {};
    res = leetcode::RemoveDuplicatesFromSortedArray::removeDuplicates(in);
    EXPECT_EQ(res, 0);

    in = {1};
    res = leetcode::RemoveDuplicatesFromSortedArray::removeDuplicates(in);
    EXPECT_EQ(res, 1);
    EXPECT_EQ(in[0], 1);

    in = {1, 1, 1};
    res = leetcode::RemoveDuplicatesFromSortedArray::removeDuplicates(in);
    EXPECT_EQ(res, 1);
    EXPECT_EQ(in[0], 1);

    in = {1, 2, 3};
    res = leetcode::RemoveDuplicatesFromSortedArray::removeDuplicates(in);
    EXPECT_EQ(res, 3);
    EXPECT_EQ(in[0], 1);
    EXPECT_EQ(in[1], 2);
    EXPECT_EQ(in[2], 3);

    in = {1, 1, 2};
    res = leetcode::RemoveDuplicatesFromSortedArray::removeDuplicates(in);
    EXPECT_EQ(res, 2);
    EXPECT_EQ(in[0], 1);
    EXPECT_EQ(in[1], 2);

    in = {1, 2, 2};
    res = leetcode::RemoveDuplicatesFromSortedArray::removeDuplicates(in);
    EXPECT_EQ(res, 2);
    EXPECT_EQ(in[0], 1);
    EXPECT_EQ(in[1], 2);

    in = {1, 1, 2, 2};
    res = leetcode::RemoveDuplicatesFromSortedArray::removeDuplicates(in);
    EXPECT_EQ(res, 2);
    EXPECT_EQ(in[0], 1);
    EXPECT_EQ(in[1], 2);

    in = {1, 1, 1, 2, 2};
    res = leetcode::RemoveDuplicatesFromSortedArray::removeDuplicates(in);
    EXPECT_EQ(res, 2);
    EXPECT_EQ(in[0], 1);
    EXPECT_EQ(in[1], 2);
}

TEST(add_two_number, test) {
    typedef leetcode::AddTwoNumbers::ListNode ListNode;
    constexpr int N = 10;
    std::vector<ListNode *> vectors;
    for (int i = 0; i < N; i++)
        vectors.push_back(new ListNode(i));

    ListNode *l1, *l2, *res;

    l1 = nullptr;
    l2 = nullptr;
    res = leetcode::AddTwoNumbers::addTwoNumbers(l1, l2);
    EXPECT_EQ(res, nullptr);

    // Reset
    for (int i = 0; i < N; i++) {
        vectors[i]->val = i;
        vectors[i]->next = nullptr;
    }

    l1 = vectors[1];
    l1->next = vectors[2];
    l1->next->next = vectors[3];
    l2 = nullptr;
    res = leetcode::AddTwoNumbers::addTwoNumbers(l1, l2);
    EXPECT_EQ(res->val, 1);
    EXPECT_EQ(res->next->val, 2);
    EXPECT_EQ(res->next->next->val, 3);

    // Reset
    for (int i = 0; i < N; i++) {
        vectors[i]->val = i;
        vectors[i]->next = nullptr;
    }

    l1 = vectors[1];
    l1->next = vectors[2];
    l1->next->next = vectors[3];
    l2 = vectors[4];
    l2->next = vectors[5];
    l2->next->next = vectors[6];
    res = leetcode::AddTwoNumbers::addTwoNumbers(l1, l2);
    EXPECT_EQ(res->val, 5);
    EXPECT_EQ(res->next->val, 7);
    EXPECT_EQ(res->next->next->val, 9);

    // Reset
    for (int i = 0; i < N; i++) {
        vectors[i]->val = i;
        vectors[i]->next = nullptr;
    }

    l1 = vectors[9];
    l2 = vectors[1];
    res = leetcode::AddTwoNumbers::addTwoNumbers(l1, l2);
    EXPECT_EQ(res->val, 0);
    EXPECT_EQ(res->next->val, 1);


    // Delete
    for (auto &node : vectors)
        delete node;
}

TEST(longest_substring_without_repeating_characters, test) {
    std::string in;
    int len;

    in = "";
    len = leetcode::LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(in);
    EXPECT_EQ(len, 0);

    in = "1111";
    len = leetcode::LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(in);
    EXPECT_EQ(len, 1);

    in = "123123";
    len = leetcode::LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(in);
    EXPECT_EQ(len, 3);

    in = "1231234";
    len = leetcode::LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(in);
    EXPECT_EQ(len, 4);

    in = "123434567";
    len = leetcode::LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(in);
    EXPECT_EQ(len, 5);

    in = "dvdf";
    len = leetcode::LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(in);
    EXPECT_EQ(len, 3);
}

TEST(longest_palindromic_substring, test) {
    std::string in, res;

    in = "";
    res = leetcode::LongestPalindromicSubstring::longestPalindrome(in);
    EXPECT_EQ(res, "");

    in = "a";
    res = leetcode::LongestPalindromicSubstring::longestPalindrome(in);
    EXPECT_EQ(res, "a");

    in = "babad";
    res = leetcode::LongestPalindromicSubstring::longestPalindrome(in);
    EXPECT_EQ(res, "bab");

    in = "cbbd";
    res = leetcode::LongestPalindromicSubstring::longestPalindrome(in);
    EXPECT_EQ(res, "bb");

    in = "aaaaa";
    res = leetcode::LongestPalindromicSubstring::longestPalindrome(in);
    EXPECT_EQ(res, in);

    in = "bananas";
    res = leetcode::LongestPalindromicSubstring::longestPalindrome(in);
    EXPECT_EQ(res, "anana");

    in = "tattarrattat";
    res = leetcode::LongestPalindromicSubstring::longestPalindrome(in);
    EXPECT_EQ(res, in);
}

TEST(zigzag_conversion, test) {
    std::string in = "PAYPALISHIRING";
    std::string res = leetcode::ZigZagConversion::convert(in, 3);
    EXPECT_EQ(res, "PAHNAPLSIIGYIR");

    in = "ABC";
    res = leetcode::ZigZagConversion::convert(in, 2);
    EXPECT_EQ(res, "ACB");

    in = "ABCD";
    res = leetcode::ZigZagConversion::convert(in, 2);
    EXPECT_EQ(res, "ACBD");

    in = "A";
    res = leetcode::ZigZagConversion::convert(in, 1);
    EXPECT_EQ(res, "A");
}

TEST(string_to_integer, test) {
    std::string in;
    int res;

    in = "";
    res = leetcode::StringToInteger::myAtoi(in);
    EXPECT_EQ(res, 0);

    in = "   12ugvbsdb";
    res = leetcode::StringToInteger::myAtoi(in);
    EXPECT_EQ(res, 12);

    in = "jsbd-176327  ";
    res = leetcode::StringToInteger::myAtoi(in);
    EXPECT_EQ(res, 0);

    in = "1-29ue28676832";
    res = leetcode::StringToInteger::myAtoi(in);
    EXPECT_EQ(res, 1);

    in = "-7562kshkhd";
    res = leetcode::StringToInteger::myAtoi(in);
    EXPECT_EQ(res, -7562);

    in = "826738923647829368923";
    res = leetcode::StringToInteger::myAtoi(in);
    EXPECT_EQ(res, 0);

    in = "+-2";
    res = leetcode::StringToInteger::myAtoi(in);
    EXPECT_EQ(res, 0);

    in = "   - 321";
    res = leetcode::StringToInteger::myAtoi(in);
    EXPECT_EQ(res, 0);
}

TEST(container_with_most_water, test) {
    std::vector<int> in;
    int res;

    in = {1};
    res = leetcode::ContainerWithMostWater::maxArea2(in);
    EXPECT_EQ(res, -1);

    in = {1, 2};
    res = leetcode::ContainerWithMostWater::maxArea2(in);
    EXPECT_EQ(res, 1);

    in = {0, 1};
    res = leetcode::ContainerWithMostWater::maxArea2(in);
    EXPECT_EQ(res, 0);

    in = {1, 2, 3, 2};
    res = leetcode::ContainerWithMostWater::maxArea2(in);
    EXPECT_EQ(res, 4);

}

TEST(integer_to_roman, test) {
    int in;
    std::string res;

    in = 39;
    res = leetcode::IntegerToRoman::intToRoman(in);
    EXPECT_EQ(res, "XXXIX");
}

TEST(three_sum, test) {
    std::vector<int> in {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> res = leetcode::ThreeSum::threeSum2(in);
    EXPECT_EQ(res.size(), 2);
}

TEST(three_sum_closet, test) {
    std::vector<int> in {-1, 2, 1, -4};
    int target = 1;
    int res = leetcode::ThreeSumCloset::threeSumClosest(in, 1);
    EXPECT_EQ(res, 2);
}

TEST(letter_combinations, test) {
    std::string in;

    in = "23";
    auto res = leetcode::LetterCombinationsOfAPhoneNumber::letterCombinations(in);
    EXPECT_EQ(res.size(), 9);

//    in = "0";
//    res = leetcode::LetterCombinationsOfAPhoneNumber::letterCombinations(in);
//    EXPECT_EQ(res.size(), 1);
//    EXPECT_EQ(res[0], " ");

    in = "239";
    res = leetcode::LetterCombinationsOfAPhoneNumber::letterCombinations(in);
    EXPECT_EQ(res.size(), 36);
}

GTEST_API_ int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}