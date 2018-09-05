//
// Created by wcj on 1/24/18.
//

#ifndef LEETCODE_15_MAX_PUBLIC_SUBSTRING_HPP
#define LEETCODE_15_MAX_PUBLIC_SUBSTRING_HPP

/// 最长公共子串
/// 两个字符串 str1 和 str2 ，返回两个字符串的最长公共子串
/// dp[i][j] = dp[i-1][j-1] + 1, str1[i] == str2[j], i, j > 0
///          = 0, str1[i] != str2[j], i, j == 0

#include <string>
#include <vector>

namespace interview {

class MaxPublicSubString {
 public:
  static std::string find(const std::string &str1, const std::string &str2) {
    if (str1.empty() || str2.empty()) return std::string();

    size_t str1Len{str1.size()}, str2Len{str2.size()};
    std::vector<std::vector<size_t>> dp(str1Len, std::vector<size_t>(str2Len, 0));

    for (ssize_t row{0}; row < str1Len; ++row)
      dp[row][0] = 0;
    for (ssize_t col{1}; col < str2Len; ++col)
      dp[0][col] = 0;

    for (ssize_t row{1}; row < str1Len; ++row) {
      for (ssize_t col{1}; col < str2Len; ++col) {
        if (str1[row] == str2[col])
          dp[row][col] = dp[row - 1][col - 1] + 1;
        else
          dp[row][col] = 0;
      }
    }

    return getSubString(str1, str2, dp);
  }

 private:
  static std::string getSubString(const std::string &str1, const std::string &str2,
                                  const std::vector<std::vector<size_t>> &dp) {
    std::size_t max = 0;
    ssize_t rowMax{0}, colMax{0};
    for (ssize_t row = 0; row < str1.size(); ++row) {
      for (ssize_t col = 0; col < str2.size(); ++col) {
        if (dp[row][col] > max)
          max = dp[row][col], rowMax = row, colMax = col;
      }
    }

    return std::string(str1.begin() + rowMax + 1 - max, str1.begin() + rowMax + 1);
  }
};

}

#endif //LEETCODE_15_MAX_PUBLIC_SUBSTRING_HPP
