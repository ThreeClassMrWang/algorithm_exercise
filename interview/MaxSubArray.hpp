//
// Created by wcj on 2/24/18.
//

#ifndef LEETCODE_MAXSUBARRAY_HPP
#define LEETCODE_MAXSUBARRAY_HPP

// 最大连续子序列和

#include <vector>
#include <climits>
#include <set>

namespace interview {

class MaxSubArraySum {
 public:
  static int maxSubArraySum(const std::vector<int>& v) {
    if (v.empty())
      return 0;

    int sum = 0, max = INT_MIN;
    for (const auto& i : v) {
      sum += i;
      max = std::max(sum, max);
      if (sum < 0) sum = 0;
    }

    std::multiset<int> set;

    return max;
  }
};

}

#endif //LEETCODE_MAXSUBARRAY_HPP
