//
// Created by wcj on 1/16/18.
//

#ifndef LEETCODE_2_SELECT_SORT_HPP
#define LEETCODE_2_SELECT_SORT_HPP

#include "SortUtil.hpp"

namespace algorithm {

class SelectSort {
 public:
  static void sort(std::vector<int> &v) {
    for (std::size_t i = 0; i < v.size(); ++i) {
      for (std::size_t j = i + 1; j < v.size(); ++j) {
        if (SortUtil::less(v[j], v[i]))
          SortUtil::exch(v[j], v[i]);
      }
    }
  }
};

}

#endif //LEETCODE_2_SELECT_SORT_HPP
