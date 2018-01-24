//
// Created by wcj on 1/24/18.
//

#ifndef LEETCODE_12_MAX_INCREASE_SUBARRAY_HPP
#define LEETCODE_12_MAX_INCREASE_SUBARRAY_HPP

/// 最长递归子序列
/// 给定数组arr，返回arr的最长递增子序列

#include <vector>
#include <cstddef>
#include <cstdio>

namespace interview {

class MaxIncreaseSubArray {
public:
    /// 首先考察O(N^2)的方法
    /// 动态规划 dp[i] 代表以 a[i] 结尾的情况下，a[0...i]中的最大递增子序列长度
    /// dp[i] = max{ dp[j] + 1, (0<=j<i, a[i] > a[j])
    static std::vector<int> find(const std::vector<int>& arr) {
        if (arr.empty()) return std::vector<int>();

        std::vector<int> dp(arr.size(), 0);
        dp[0] = 1;
        for (ssize_t i{1}; i < arr.size(); ++i) {
            int max = 1;
            for (ssize_t j{0}; j < i; ++j)
                if (arr[i] > arr[j])
                    max = std::max(max, dp[j] + 1);
            dp[i] = max;
        }

        return getSubArray(arr, dp);
    }

    /// O(NlogN) 主要是在dp产生时进行优化
    /// 因为 dp 每次遍历时有可以重复使用的数据
    static std::vector<int> find2(const std::vector<int>& arr) {
        if (arr.empty()) return std::vector<int>();

        std::vector<int> dp(arr.size(), 0), ends(arr.size(), 0);
        ssize_t right{0};

        // Init
        dp[0] = 1;
        ends[right] = arr[0];

        for (ssize_t i{1}; i < arr.size(); ++i) {
            ssize_t l{0}, h{right}, m;
            while (l <= h) {
                m = l + (h - l) / 2;
                if (arr[i] > ends[m])
                    l = m + 1;
                else
                    h = m - 1;
            }

            if (l > right) right = l;
            ends[l] = arr[i];
            dp[i] = (int)l + 1;
        }

        return getSubArray(arr, dp);
    }

private:
    static std::vector<int> getSubArray(const std::vector<int>& arr, const std::vector<int>& dp) {
        // After getting dp, we find
        int max = dp[0];
        ssize_t idx = 0;
        for (ssize_t i{0}; i < dp.size(); ++i) {
            if (dp[i] > max)
                max = dp[i], idx = i;
        }

        std::vector<int> subArray(max, 0);
        subArray[max-1] = arr[idx];
        ssize_t target = max - 2;
        for (ssize_t i = idx; i >= 0; --i) {
            if (subArray[target+1] > arr[i] && target + 1 == dp[i]) {
                subArray[target] = arr[i];
                --target;
            }
        }

        return subArray;
    }
};

}

#endif //LEETCODE_12_MAX_INCREASE_SUBARRAY_HPP
