//
// Created by wcj on 1/24/18.
//

#ifndef LEETCODE_16_MIN_EDIT_COST_HPP
#define LEETCODE_16_MIN_EDIT_COST_HPP

/// 最小编辑代价
/// 给定字符串 str1 和 str2，再给定三个整数 ic, dc, rc, 分别代表插入、删除和替换一个字符的代价
/// 返回讲str1编辑为str2的最小
/// 动态规划： (M+1)(N+1) dp[i][j] 代表 str1[0...i] 编辑成 str2[0...j] 代价
///

#include <string>
#include <vector>

namespace interview {

class MinEditCost {
 public:
  static std::size_t cost(const std::string &str1,
                          const std::string &str2,
                          std::size_t ic,
                          std::size_t dc,
                          std::size_t rc) {
    std::size_t str1Len{str1.size()}, str2Len(str2.size());
    std::vector<std::vector<std::size_t>> dp(str1Len + 1, std::vector<std::size_t>(str2Len + 1, 0));

    dp[0][0] = 0;
    for (ssize_t row{1}; row <= str1Len; ++row)
      dp[row][0] = row * dc;
    for (ssize_t col{1}; col <= str2Len; ++col)
      dp[0][col] = col * ic;

    for (ssize_t row{1}; row <= str1Len; ++row) {
      for (ssize_t col{1}; col <= str2Len; ++col) {
        // 状态转移的4种情况
        if (str1[row - 1] == str2[col - 1])
          dp[row][col] = dp[row - 1][col - 1];
        else
          dp[row][col] = dp[row - 1][col - 1] + rc;
        dp[row][col] = std::min(dp[row][col], dp[row - 1][col] + dc);
        dp[row][col] = std::min(dp[row][col], dp[row][col - 1] + ic);
      }
    }

    return dp[str1Len][str2Len];
  }
};

}

#endif //LEETCODE_16_MIN_EDIT_COST_HPP
