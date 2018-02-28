//
// Created by wcj on 17-11-14.
//

#ifndef LEETCODE_14_LONGEST_COMMON_PREFIX_H
#define LEETCODE_14_LONGEST_COMMON_PREFIX_H

//Write a function to find the longest common prefix string amongst an array of strings.

#include <string>
#include <vector>
#include <climits>

namespace leetcode {
class LongestCommonPrefix {
 public:
  static std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.size() == 0)
      return std::string("");

    std::size_t len = ULLONG_MAX;
    for (const auto &s : strs) {
      if (s.length() < len)
        len = s.length();
    }

    std::size_t i = 0;
    for (; i < len; i++) {
      char p = strs[0][i];
      std::size_t j = 0;

      for (; j < strs.size(); ++j)
        if (strs[j][i] != p)
          goto exit_;
    }

    exit_:
    return std::string(strs[0].begin(), strs[0].begin() + i);
  }
};
}

#endif //LEETCODE_14_LONGEST_COMMON_PREFIX_H
