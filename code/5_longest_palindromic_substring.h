//
// Created by wcj on 17-11-30.
//

#ifndef LEETCODE_5_LONGEST_PALINDROMIC_SUBSTRING_H
#define LEETCODE_5_LONGEST_PALINDROMIC_SUBSTRING_H

#include <string>

//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example:
//
//        Input: "babad"
//
//Output: "bab"
//
//Note: "aba" is also a valid answer.
//Example:
//
//        Input: "cbbd"
//
//Output: "bb"

namespace leetcode {
class LongestPalindromicSubstring {
 public:
  static std::string longestPalindrome(std::string s) {
    if (s.empty())
      return std::string("");

    std::pair<size_t, size_t> longest(0, 0);
    std::pair<size_t, size_t> last(0, 0);
    for (size_t i = 1; i < s.length(); ++i) {
      if (s[i] == s[i - 1]) {
        last = std::pair<size_t, size_t>(last.first, i);
        continue;
      }

      // huisu
      ssize_t lidx = last.first;
      size_t ridx = last.second;
      while (lidx >= 0 && ridx < s.length() && s[ridx] == s[lidx]) {
        --lidx;
        ++ridx;
      }
      if (ridx - lidx - 2 > longest.second - longest.first)
        longest = std::pair<size_t, size_t>(lidx + 1, ridx - 1);

      lidx = i - 1;
      ridx = i + 1;
      while (lidx >= 0 && ridx < s.length() && s[ridx] == s[lidx]) {
        --lidx;
        ++ridx;
      }
      if (ridx - lidx - 2 > longest.second - longest.first)
        longest = std::pair<size_t, size_t>(lidx + 1, ridx - 1);
      last = std::pair<size_t, size_t>(i, i);
    }
    if (last.second - last.first > longest.second - longest.first)
      longest = last;
    return std::string(s.begin() + longest.first, s.begin() + longest.second + 1);
  }
};
}

#endif //LEETCODE_5_LONGEST_PALINDROMIC_SUBSTRING_H
