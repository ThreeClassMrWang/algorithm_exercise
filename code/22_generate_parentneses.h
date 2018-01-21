//
// Created by wcj on 1/9/18.
//

#ifndef LEETCODE_22_GENERATE_PARENTNESES_H
#define LEETCODE_22_GENERATE_PARENTNESES_H

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//[
//"((()))",
//"(()())",
//"(())()",
//"()(())",
//"()()()"
//]

#include <vector>
#include <string>

namespace leetcode {
class GenerateParentesis {
public:
    static std::vector<std::string> generateParentesis(int n) {
        if (n == 0) return {""};        // or {}
        std::vector<std::string> vec;
        generateParentesis(vec, "", 0, 0, n);
        return vec;
    }

    static void generateParentesis(std::vector<std::string> &vec, std::string str, int open, int close, int max) {
        if (str.length() == max * 2) {
            vec.push_back(str);
            return;
        }

        if (open < max)
            generateParentesis(vec, std::move(str + "("), open + 1, close, max);
        if (close < open)
            generateParentesis(vec, std::move(str + ")"), open, close + 1, max);
    }
};
}

#endif //LEETCODE_22_GENERATE_PARENTNESES_H
