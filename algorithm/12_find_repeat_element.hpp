//
// Created by wcj on 1/20/18.
//

#ifndef LEETCODE_12_FIND_REPEAT_ELEMENT_HPP
#define LEETCODE_12_FIND_REPEAT_ELEMENT_HPP

#include <vector>
#include <algorithm>

namespace algorithm {

class FindRepeatElement {
public:

/// 一个大小为n的数组，里面的数都属于范围[0, n-1]，有不确定的重复元素，找到至少一个重复元素.
/// 要求O(1)空间和O(n)时间。
///
/// \param v
/// \return
    static int findRepeatElement(std::vector<int>& v) {
        for (std::size_t i = 0; i < v.size(); ++i) {
            if (v[i] >= 0) {
                if (v[v[i]] < 0)
                    return v[i];
                else
                    v[v[i]] = -v[v[i]] - 1;
            } else {
                int ori = -v[i] - 1;
                if (v[ori] < 0)
                    return ori;
                else
                    v[ori] = -v[ori] - 1;
            }
        }
        return -1;
    }

    /// 一个数组中含有1001个元素，存放了1,2,3...1000和一个重复的数。
    /// 只有唯一一个数是重复的，其它均只出现一次。
    /// 要求设计一个算法找出这个重复的数，要求：每个数组元素只能访问一次，不用辅助存储空间。

    static int findUniqueNumber_1(const std::vector<int>& v) {
        // Sum of number
        int sum = 0;
        for (const auto& item : v)
            sum += item;

        // Sum of 1 ... 1000
        constexpr int sum2 = 500 * 1001;

        return sum - sum2;
    }

    // b ^ a ^ b = a
    static int findUniqueNumber_2(const std::vector<int>& v) {
        int bab = v[0];
        for (std::size_t i = 1; i < v.size(); ++i)
            bab ^= v[i];
        for (int i = 1; i <= 1000; ++i)
            bab ^= i;
        return bab;
    }
};

}

#endif //LEETCODE_12_FIND_REPEAT_ELEMENT_HPP
