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
            if (digits.empty() || digits == "1") return std::vector<std::string>();
            std::vector<std::string> res = {""};
            for (int i = 0; i < digits.size(); ++i) {
                if (digits[i] == '1') continue;
                std::vector<std::string> r;
                const std::string s = map[digits[i] - '0'];
                for (int j = 0; j < res.size(); ++j) {
                    for (int k = 0; k < s.size(); ++k)
                        r.emplace_back(std::string(res[j] + s[k]));
                }
                res = r;
            }

            return res;
        }

    private:
        static std::vector<std::string> map;
    };

    std::vector<std::string> LetterCombinationsOfAPhoneNumber::map = {
            " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
}

#endif //LEETCODE_17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
