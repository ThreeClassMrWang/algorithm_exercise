//
// Created by wcj on 17-11-14.
//

#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "code.h"
#include "14_longest_common_prefix.h"
#include "20_valid_parentheses.h"

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

    in = {"abchug", "abcde"};
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

GTEST_API_ int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}