//
// Created by wcj on 3/1/18.
//

#ifndef LEETCODE_007_HEAP_SORT_HPP
#define LEETCODE_007_HEAP_SORT_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class HeapSort007 {
 public:
  static void sort(std::vector<int>& v) {
    if (v.empty()) return;

    v.push_back(v[0]);

    ssize_t N = v.size() - 1;
    for (ssize_t k = N / 2; k >= 1; --k )
      sink(v, k, N);

    while (N > 1) {
      std::swap(v[1], v[N--]);
      sink(v, 1, N);
    }

    v = std::vector<int>(v.cbegin() + 1, v.cend());
  }

 private:
  static void sink(std::vector<int>& v, ssize_t k, ssize_t N) {
    while (2 * k <= N) {
      ssize_t j = 2 * k;
      if (j < N && SortUtil::less(v[j], v[j + 1])) ++j;
      if (!SortUtil::less(v[k], v[j])) break;
      std::swap(v[k], v[j]);
      k = j;
    }
  }
};

}

#endif //LEETCODE_007_HEAP_SORT_HPP
