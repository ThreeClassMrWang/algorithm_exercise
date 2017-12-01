//
// Created by wcj on 17-12-1.
//

#ifndef LEETCODE_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define LEETCODE_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H

#include <vector>
#include <string>
#include <exception>
#include <stdexcept>

namespace leetcode {
    class LetterCombinationsOfAPhoneNumber {
    public:
        static std::vector<std::string> letterCombinations(std::string digits) {
            std::vector<std::string> res;
            for (size_t i = 0; i < digits.size(); ++i)
                letterCombinations(digits, i, res);
            return res;
        }

    private:
        static std::vector<std::string> letterCombinations(const std::string &digits, size_t idx, std::vector<std::string> &old_res) {
            if (!checkInteger(digits[idx])) throw std::invalid_argument("digits should be only contains numbers");
            std::vector<std::string> r;
            for (const auto &c : map[digits[idx]-'0']) {
                if (old_res.empty())
                    r.push_back("" + c);
                else {
                    for (const auto &s : old_res)
                        r.push_back(s + c);
                }
            }
            return r;
        }

        static bool checkInteger(const char c) {
            return c >= '0' && c <= '9';
        }

        static std::vector<std::string> map;
    };

    std::vector<std::string> LetterCombinationsOfAPhoneNumber::map = {
            " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
}

#endif //LEETCODE_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
