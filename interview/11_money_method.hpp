//
// Created by wcj on 1/24/18.
//

#ifndef LEETCODE_10_MONEY_METHOD_HPP
#define LEETCODE_10_MONEY_METHOD_HPP

#include <cstddef>
#include <vector>
#include <cstdio>

namespace interview {

class MoneyMethod {
public:
    static int find(const std::vector<int>& arr, int aim) {
        if (arr.empty() || aim < 0) return 0;

        std::vector<std::vector<int>> dp(arr.size(), std::vector<int>(aim+1, 0));
        for (ssize_t row{0}; row < arr.size(); ++row)
            dp[row][0] = 1;

        for (ssize_t col{1}; arr[0] * col <= aim; ++col)
            dp[0][arr[0]*col] = 1;

        for (ssize_t row{1}; row < arr.size(); ++row) {
            for (ssize_t col{1}; col <= aim; ++col) {
                dp[row][col] = dp[row - 1][col];
                if (col >= arr[row])
                    dp[row][col] += dp[row][col-arr[row]];
            }
        }

        return dp[arr.size()-1][aim];
    }

    static int find_op(const std::vector<int>& arr, int aim) {
        if (arr.empty() || aim < 0) return 0;

        std::vector<int> dp(aim+1, 0);
        dp[0] = 1;

        for (ssize_t col{1}; arr[0] * col <= aim; ++col)
            dp[arr[0]*col] = 1;

        for (ssize_t row{1}; row < arr.size(); ++row) {
            for (ssize_t col{1}; col <= aim; ++col) {
                if (col >= arr[row])
                    dp[col] += dp[col - arr[row]];
            }
        }

        return dp[aim];
    }
};

}

#endif //LEETCODE_10_MONEY_METHOD_HPP
