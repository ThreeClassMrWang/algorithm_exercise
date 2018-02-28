//
// Created by wcj on 1/20/18.
//

#ifndef LEETCODE_13_KANDALL_DISTANCE_HPP
#define LEETCODE_13_KANDALL_DISTANCE_HPP

/// 计算两个数组之间的 kandall tau 距离。
/// 例如 [0 3 1 6 2 5 4] 与 [1 0 3 6 4 2 5] 距离为4

#include <vector>
#include <unordered_map>

namespace algorithm {

class KandallDistance {
 public:
  static int calcutate(const std::vector<int> &a, const std::vector<int> &b) {
    std::unordered_map<int, int> map;
    int i = 0;
    for (const auto &item : a)
      map[item] = i++;

    std::vector<int> c(b.size(), 0);
    i = 0;
    for (const auto &item : b)
      c[i++] = map[item];

    int sum = 0;
    for (i = 0; i < b.size(); ++i)
      if (c[i] > i)
        sum += (c[i] - i);
    return sum;
  }
};

}

#endif //LEETCODE_13_KANDALL_DISTANCE_HPP
