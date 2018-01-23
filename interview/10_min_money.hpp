//
// Created by wcj on 1/24/18.
//

#ifndef LEETCODE_10_MIN_MONEY_HPP
#define LEETCODE_10_MIN_MONEY_HPP

/// 换钱的最小货币数，有两个变种
/// 一个是货币可以重复使用，二是货币只有一张

#include <vector>

namespace interview {

class MinMoney {
public:
    /// 1. 给定数组arr，arr中的所有数都为整数，且不重复，每个值代表一种面值的货币，每种面值的货币可以使用任意张
    /// 再给定一个整数 aim 代表要找出的钱数，求组成 aim 的最小货币数
    /// dp[i][j] 代表使用货币arr[0...i]的基础上总钱数为j所需求的最小货币数
    /// dp[i][j] = min(dp[i-1][j], dp[i][j-arr[i]]+1), if j >= arr[i]
    ///             dp[i-1][j], if j < arr[i]
    /// 从上述递推关系中可以dp的求取顺序为从左到右，从上到下
    static int find1(const std::vector<int>& arr, int aim) {
        if (arr.empty() || aim < 0) return -1;
        std::vector<std::vector<int>> dp(arr.size(), std::vector<int>(aim+1, 0));

        for (ssize_t col{1}; col <= aim; ++col) {
            dp[0][col] = -1;
            if (col - arr[0] >= 0 && dp[0][col - arr[0]] != -1)
                dp[0][col] = dp[0][col - arr[0]] + 1;
        }

        for (ssize_t row{1}; row < arr.size(); ++row) {
            for (size_t col{1}; col <= aim; ++col) {
                if (col >= arr[row] && dp[row][col-arr[row]] != -1) {
                    if (dp[row - 1][col] != -1)
                        dp[row][col] = std::min(dp[row - 1][col], dp[row][col - arr[row]] + 1);
                    else
                        dp[row][col] = dp[row][col - arr[row]] + 1;
                }
                else
                    dp[row][col] = std::max(-1, dp[row-1][col]);
            }
        }

        return dp[arr.size()-1][aim];
    }

    static int find1_op(const std::vector<int>& arr, int aim) {
        /// 行压缩
        if (arr.empty() || aim < 0) return -1;
        std::vector<int> dp(aim+1, 0);

        for (ssize_t col{1}; col <= aim; ++col) {
            dp[col] = -1;
            if (col >= arr[0] && dp[col-arr[0]] != -1)
                dp[col] = dp[col-arr[0]] + 1;
        }

        // 压缩
        for (ssize_t row{1}; row < arr.size(); ++row) {
            for (ssize_t col{1}; col <= aim; ++col) {
                if (col >= arr[row] && dp[col-arr[row]] != -1)
                    dp[col] = std::min(dp[col], dp[col-arr[row]]+1);
                else
                    dp[col] = std::max(-1, dp[col]);
            }
        }

        return dp[aim];
    }

    /// 2. 每一个数组代表一张钱
    static int find2(const std::vector<int>& arr, int aim) {
        if (arr.empty() || aim < 0) return -1;

        std::vector<std::vector<int>> dp(arr.size(), std::vector<int>(aim+1, 0));
        for (ssize_t col{1}; col <= aim; ++col) {
            dp[0][col] = -1;
        }

        if (arr[0] <= aim)
            dp[0][arr[0]] = 1;

        for (ssize_t row{1}; row < arr.size(); ++row) {
            for (ssize_t col{1}; col <= aim; ++col) {
                if (col >= arr[row] && dp[row-1][col-arr[row]] != -1) {
                    if (dp[row-1][col] != -1)
                        dp[row][col] = std::min(dp[row - 1][col], dp[row - 1][col - arr[row]] + 1);
                    else
                        dp[row][col] = dp[row - 1][col - arr[row]] + 1;
                }
                else
                    dp[row][col] = std::max(-1, dp[row-1][col]);
            }
        }

        return dp[arr.size()-1][aim];
    }
};

}

#endif //LEETCODE_10_MIN_MONEY_HPP
