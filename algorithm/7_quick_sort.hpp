//
// Created by wcj on 1/19/18.
//

#ifndef LEETCODE_7_QUICK_SORT_HPP
#define LEETCODE_7_QUICK_SORT_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class QuickSort {
 public:
  static void sort(std::vector<int> &v) {
    sort(v, 0, v.size() - 1);
  }

 private:
  static void sort(std::vector<int> &v, ssize_t lo, ssize_t hi) {
    if (lo >= hi) return;
    ssize_t j = partition(v, lo, hi);
    sort(v, lo, j - 1);
    sort(v, j + 1, hi);
  }

  static ssize_t partition(std::vector<int> &v, ssize_t lo, ssize_t hi) {
    int target = v[lo];
    ssize_t i = lo, j = hi + 1;
    while (true) {
      while (SortUtil::less(v[++i], target)) if (i == hi) break;
      while (SortUtil::less(target, v[--j])) if (j == lo) break;
      if (i >= j) break;
      SortUtil::exch(v[i], v[j]);
    }
    SortUtil::exch(v[lo], v[j]);
    return j;
  }
};

}

#endif //LEETCODE_7_QUICK_SORT_HPP
