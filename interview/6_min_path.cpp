//
// Created by wcj on 1/9/18.
//

#include <vector>
#include <iostream>

static std::vector<std::vector<int>> m = {
        {1, 3, 5, 9},
        {8, 1, 3, 4},
        {5, 0, 6, 1},
        {8, 8, 4, 0},
};

int minPathSum(const std::vector<std::vector<int>> m) {
    if (m.empty()) return 0;

    std::size_t row = m.size();
    std::size_t col = m[0].size();
    std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));

    dp[0][0] = m[0][0];

    // init row
    for (std::size_t i = 1; i < row; ++i)
        dp[i][0] = dp[i-1][0] + m[i][0];
    // init col
    for (std::size_t j = 1; j < col; ++j)
        dp[0][j] = dp[0][j-1] + m[0][j];

    // Fill dp
    for (std::size_t i = 1; i < row; ++i) {
        for (std::size_t j = 1; j < col; ++j) {
            dp[i][j] = std::min(dp[i][j-1], dp[i-1][j]) + m[i][j];
        }
    }

    return dp[row-1][col-1];
}

int main(int, char**) {
    std::cout << "minSumPath: " << minPathSum(m) << std::endl;
}
