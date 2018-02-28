//
// Created by wcj on 1/20/18.
//

#ifndef LEETCODE_15_BINARY_SEARCH_HPP
#define LEETCODE_15_BINARY_SEARCH_HPP

#include <vector>
#include <cstdio>

namespace algorithm {

class BinarySearch {
 public:
  static ssize_t search(std::vector<int> &v, int key) {
    ssize_t lo = 0, hi = v.size() - 1;
    while (lo <= hi) {
      ssize_t mid = lo + (hi - lo) / 2;
      if (v[mid] == key) return mid;
      else if (v[mid] > key) hi = mid - 1;
      else lo = mid + 1;
    }

    return -1;
  }
};

}

#endif //LEETCODE_15_BINARY_SEARCH_HPP
