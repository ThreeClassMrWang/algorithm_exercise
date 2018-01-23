//
// Created by wcj on 1/23/18.
//

#ifndef LEETCODE_354_MAX_LENGTH_HPP
#define LEETCODE_354_MAX_LENGTH_HPP

/// 给定数组arr, 该数组无序，但每个值为正数，再给定一个正数k，求arr所有子数组所有元素相加和为k的最长数组长度
/// 例如 arr = [1,2,1,1,1], k = 3
/// 结果为 [1, 1, 1] 3

#include <cstddef>
#include <vector>
#include <functional>

namespace interview {

class MaxLengthSubArray {
public:
    static std::size_t find(const std::vector<int>& v, int k) {
        if (v.empty() || k <= 0)
            return 0;

        int sum{v[0]};
        std::size_t left{0}, right{0}, len{0};

        while (right < v.size()) {
            if (sum == k) {
                len = std::max(len, right - left + 1);
                sum -= v[left++];
            } else if (sum > k) {
                sum -= v[left++];
            } else {
                ++right;
                if (right == v.size()) break;
                sum += v[right];
            }
        }

        return len;
    }
};

}

#endif //LEETCODE_354_MAX_LENGTH_HPP
