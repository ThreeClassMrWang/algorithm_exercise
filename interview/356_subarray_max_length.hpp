//
// Created by wcj on 1/23/18.
//

#ifndef LEETCODE_356_SUBARRAY_MAX_LENGTH_HPP
#define LEETCODE_356_SUBARRAY_MAX_LENGTH_HPP

/// 未排序数组中累积和为固定值的最长子数组
/// 无序数组arr，可正可负可为零, 求和为k的最长子数组长度

///!!! 补充问题1
/// 给定一个无序数组，其中元素可正，可负可为0，求arr所有子数组中正数和负数相等的最长子数组长度

///!!! 补充问题2
/// 给定一个无序数组arr， 其中元素只能为0或者1， 求arr所有子数组中0和1相等的最长子数组长度

#include <vector>
#include <unordered_map>

namespace interview {

class SubarrayMaxLength {
 public:
  static ssize_t find(const std::vector<int> &arr, int k) {
    if (arr.empty()) return 0;

    std::unordered_map<int, ssize_t> map;
    map[0] = -1;

    int sum{0};
    ssize_t len{0};
    for (ssize_t i = 0; i < arr.size(); ++i) {
      sum += arr[i];
      auto it = map.find(sum - k);
      if (it != map.end())
        len = std::max(len, i - it->second);
      it = map.find(sum);
      if (it == map.end())
        map[sum] = i;
    }

    return len;
  }

};

}

#endif //LEETCODE_356_SUBARRAY_MAX_LENGTH_HPP
