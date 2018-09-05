//
// Created by wcj on 2/28/18.
//

#ifndef LEETCODE_001_SELECT_SORT_HPP
#define LEETCODE_001_SELECT_SORT_HPP

#include <vector>

namespace algorithm {

class SelectSort001 {
 public:
  static void selectSort(std::vector<int>& v) {
    for (std::size_t i = 0; i < v.size(); ++i) {
      int min = v[i];
      std::size_t minIdx = i;
      for (std::size_t j = i; j < v.size(); ++j) {
        if (v[j] < min)
          min = v[j], minIdx = j;
      }
      std::swap(v[i], v[minIdx]);
    }
  }

};

}

#endif //LEETCODE_001_SELECT_SORT_HPP
