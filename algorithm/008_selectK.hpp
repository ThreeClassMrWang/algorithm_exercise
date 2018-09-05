//
// Created by wcj on 3/1/18.
//

#ifndef LEETCODE_SELECTK_HPP
#define LEETCODE_SELECTK_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class SelectK008 {
 public:
  static int selectK(std::vector<int>& v, ssize_t k) {
    ssize_t lo = 0, hi = v.size() - 1;
    while (lo < hi) {
      ssize_t j = partition(v, lo, hi);
      if (j == k) break;
      else if (j > k) hi = j - 1;
      else lo = j + 1;
    }

    return v[k];
  }

 private:
  static ssize_t partition(std::vector<int>& v, ssize_t lo, ssize_t hi) {
    ssize_t i = lo, j = hi + 1;
    int target = v[lo];
    while (true) {
      while(SortUtil::less(v[++i], target)) if (i >= hi) break;
      while(SortUtil::less(target, v[--j])) if (j <= lo) break;
      if (i >= j) break;
      std::swap(v[i], v[j]);
    }
    std::swap(v[lo], v[j]);

    return j;
  }
};

}

#endif //LEETCODE_SELECTK_HPP
