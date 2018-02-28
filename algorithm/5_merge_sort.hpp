//
// Created by wcj on 1/18/18.
//

#ifndef LEETCODE_5_MERGE_SORT_HPP
#define LEETCODE_5_MERGE_SORT_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class MergeSort {
 public:
  static void sort(std::vector<int> &v) {
    sort(v, 0, v.size() - 1);
  }

 private:

  static void sort(std::vector<int> &v, std::size_t lo, std::size_t hi) {
    if (lo >= hi) return;
    std::size_t mid = lo + (hi - lo) / 2;
    sort(v, lo, mid);
    sort(v, mid + 1, hi);
    merge(v, lo, mid, hi);
  }

  static void merge(std::vector<int> &v, std::size_t lo, std::size_t mid, std::size_t hi) {
    static std::vector<int> aux(v.size(), 0);
    for (std::size_t k = lo; k <= hi; ++k)
      aux[k] = v[k];

    std::size_t i = lo, j = mid + 1;
    for (std::size_t k = lo; k <= hi; ++k) {
      if (i > mid) v[k] = aux[j++];
      else if (j > hi) v[k] = aux[i++];
      else if (SortUtil::less(aux[j], aux[i])) v[k] = aux[j++];
      else v[k] = aux[i++];
    }
  }

};

}

#endif //LEETCODE_5_MERGE_SORT_HPP
