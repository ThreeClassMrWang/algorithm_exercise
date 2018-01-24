//
// Created by wcj on 1/24/18.
//

#ifndef LEETCODE_14_MAX_PUBLIC_SUBARRAY_HPP
#define LEETCODE_14_MAX_PUBLIC_SUBARRAY_HPP

/// 最长公共子序列
/// 给定两个字符串str1和str2，返回两个字符串
/// 动态规划： dp[i][j] 表示str1[0...i]和str2[0...j]的最长公共子序列的长度
/// dp[i][j] = dp[i-1][j-1] + 1, if str1[i] == str1[j], i, j > 0
///          = max{ dp[i-1][j], dp[i][j-1], if str1[i] != str2[j], i, j > 0
///          = 0, if i == 0 || j == 0
///  由此可知 dp 需要从左到右，从上到下填充

#include <string>
#include <vector>

namespace interview {

class MaxPublicSubArray {
public:
    static std::string find(const std::string& str1, const std::string& str2) {
        std::vector<std::vector<size_t>> dp(str1.size(), std::vector<size_t>(str2.size(), 0));

        std::size_t str1Len{str1.size()}, str2Len{str2.size()};
        for (size_t row{0}; row < str1Len; ++row)
            dp[row][0] = 0;
        for (size_t col{1}; col < str2Len; ++col)
            dp[0][col] = 0;

        for (size_t row{1}; row < str1Len; ++row) {
            for (size_t col{1}; col < str2Len; ++col) {
                if (str1[row] == str2[col])
                    dp[row][col] = dp[row-1][col-1] + 1;
                else
                    dp[row][col] = std::max(dp[row-1][col], dp[row][col-1]);
            }
        }

        return getSubArray(str1, str2, dp);
    }

private:
    /// Get subArray from dp
    ///
    /// \param str1
    /// \param str2
    /// \param dp
    /// \return SubArrayString
    static std::string getSubArray(const std::string& str1, const std::string& str2, const std::vector<std::vector<size_t>>& dp) {
        std::string res(dp[str1.size()-1][str2.size()-1] + 1, 0); // note: res.size = max{dp[i][j]} + 1

        ssize_t idx{(ssize_t)res.size() - 1};
        ssize_t row{(ssize_t)str1.size() - 1}, col{(ssize_t)str2.size() - 1};
        while(idx >= 0) {
            if (row > 0 && dp[row][col] == dp[row-1][col])
                --row;
            else if (col > 0 && dp[row][col] == dp[row][col-1])
                --col;
            else {
                res[idx--] = str1[row];
                --row;
                --col;
            }
        }

        return res;
    }
};

}

#endif //LEETCODE_14_MAX_PUBLIC_SUBARRAY_HPP
