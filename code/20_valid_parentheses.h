//
// Created by wcj on 17-11-15.
//

#ifndef LEETCODE_20_VALID_PARENTHESES_H
#define LEETCODE_20_VALID_PARENTHESES_H

#include <string>
#include <stack>

namespace leetcode {
    class ValidParentheses {
    public:
        static bool isValid(std::string s) {
            std::stack<char> stk;
            for (const auto &c : s) {
                if (c == '(' || c == '{' || c == '[')
                    stk.push(c);
                else {
                    if (stk.empty() || (!stk.empty() && !isCorrect(stk.top(), c)))
                        return false;
                    else
                        stk.pop();
                }
            }

            return stk.empty();
        }

    private:
        static bool isCorrect(const char &a, const char &b) {
            return ((a == '(' && b == ')') ||
                    (a == '{' && b == '}') ||
                    (a == '[' && b == ']'));
        }
    };
}

#endif //LEETCODE_20_VALID_PARENTHESES_H
