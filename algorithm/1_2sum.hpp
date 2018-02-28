//
// Created by wcj on 1/16/18.
//

#ifndef LEETCODE_1_2SUM_HPP
#define LEETCODE_1_2SUM_HPP

#include <vector>
#include <unordered_set>

namespace algorithm {

class TwoSum {
 public:
  static bool twoSum1(std::vector<int> array, int sum) {
    std::unordered_set<int> set;
    for (const auto &item : array) {
      int target = sum - item;
      auto it = set.find(target);
      if (it != set.end()) {
        return true;
      } else {
        set.insert(item);
      }
    }
  }
};

}

#endif //LEETCODE_1_2SUM_HPP
