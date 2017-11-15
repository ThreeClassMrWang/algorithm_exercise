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

    for (auto &node : vectors)
        delete node;
}

GTEST_API_ int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}