//
// Created by wcj on 2/28/18.
//

#ifndef LEETCODE_005_QUICK_SORT_HPP
#define LEETCODE_005_QUICK_SORT_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class QuickSort005 {
 public:
  static void sort(std::vector<int>& v) {
    sort(v, 0, v.size() - 1);
  }

  static void sort3Way(std::vector<int>& v) {
    sort3Way(v, 0, v.size() - 1);
  }

 private:

  static void sort3Way(std::vector<int>& v, ssize_t lo, ssize_t hi) {
    if (lo >= hi) return;
    int target = v[lo];

    ssize_t lt = lo, i = lo + 1, gt = hi;
    while (i <= gt) {
      if (SortUtil::less(v[i], target)) std::swap(v[lt++], v[i++]);
      else if(SortUtil::less(target, v[i])) std::swap(v[i], v[gt--]);
      else ++i;
    }

    sort3Way(v, lo, lt - 1);
    sort3Way(v, gt + 1, hi);
  }

  static void sort(std::vector<int>& v, ssize_t lo, ssize_t hi) {
    if (lo >= hi) return;
    ssize_t j = partition(v, lo, hi);
    sort(v, lo, j - 1);
    sort(v, j + 1, hi);
  }

  static ssize_t partition(std::vector<int>& v, ssize_t lo, ssize_t hi) {
    ssize_t i = lo, j = hi + 1;
    int target = v[lo];

    while (true) {
      while (SortUtil::less(v[++i], target)) if (i >= hi) break;
      while (SortUtil::less(target, v[--j])) if (j <= lo) break;
      if (i >= j) break;
      std::swap(v[i], v[j]);
    }
    std::swap(v[lo], v[j]);
    return j;
  }
};

}

#endif //LEETCODE_005_QUICK_SORT_HPP
