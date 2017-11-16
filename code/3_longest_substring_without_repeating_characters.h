//
// Created by wcj on 17-11-16.
//

#ifndef LEETCODE_3_LONGEST_SUBSTRING_WITHOUT_CHARACTERS_H
#define LEETCODE_3_LONGEST_SUBSTRING_WITHOUT_CHARACTERS_H

//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//        Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <string>
#include <unordered_map>

namespace leetcode {
    class LongestSubstringWithoutRepeatingCharacters {
    public:
        static int lengthOfLongestSubstring(const std::string &s) {
            std::size_t len = 0;

            std::unordered_map<char, int> m;
            std::unordered_map<char, int>::iterator it;
            int lastIdx = 0;
            for (int i = 0; i < s.size(); ++i) {
                if ((it = m.find(s[i])) == m.end()) {
                    m[s[i]] = i;
                } else {
                    len = m.size() > len ? m.size() : len;
                    int idx = it->second;
                    // Erase before
                    for (int j = lastIdx; j <= idx; ++j)
                        m.erase(s[j]);
                    lastIdx = idx + 1;
                    m[s[i]] = i;
                }
            }
            len = m.size() > len ? m.size() : len;

            return (int)len;
        }
    };
}

#endif //LEETCODE_3_LONGEST_SUBSTRING_WITHOUT_CHARACTERS_H
