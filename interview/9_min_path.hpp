//
// Created by wcj on 1/23/18.
//

#ifndef LEETCODE_8_MIN_PATH_HPP
#define LEETCODE_8_MIN_PATH_HPP

/// 矩阵的最小路径和

#include <cstddef>
#include <vector>

namespace interview {

class MinPath {
public:
    static int find(const std::vector<std::vector<int>>& v) {
        if (v.empty() || (!v.empty() && v[0].empty()))
            return 0;
        std::size_t M{v.size()}, N{v[0].size()};
        std::vector<std::vector<int>> dp(M, std::vector<int>(N, 0));
        dp[0][0] = v[0][0];

        for (std::size_t row{1}; row < M; ++row)
            dp[row][0] = dp[row -1][0] + v[row][0];
        for (std::size_t col{1}; col < N; ++col)
            dp[0][col] = dp[0][col-1] + v[0][col];

        for (std::size_t row{1}; row < M; ++row) {
            for (std::size_t col{1}; col < N; ++col)
                dp[row][col] = std::min(dp[row-1][col], dp[row][col-1]) + v[row][col];
        }

        return dp[M-1][N-1];
    }

    /// 空间压缩的方法
    static int find_op(const std::vector<std::vector<int>>& v) {
        if (v.empty() || (!v.empty() && v[0].empty())) return 0;
        std::size_t M{v.size()}, N{v[0].size()};
        std::vector<int> dp(std::max(M, N), 0);

        // 随便选择一个方向进行压缩，这里选择行压缩
        dp[0] = v[0][0];
        for (std::size_t col{1}; col < N; ++col)
            dp[col] = dp[col-1] + v[0][col];
        // 逐行压缩
        for (std::size_t row{1}; row < M; ++row) {
            for (std::size_t col{0}; col < N; ++col)
                dp[col] = std::min(dp[col-1], dp[col]) + v[row][col];
        }

        return dp[N-1];
    }
};

}

#endif //LEETCODE_8_MIN_PATH_HPP
