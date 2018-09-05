//
// Created by wcj on 2/28/18.
//

#ifndef LEETCODE_002_INSERT_SORT_HPP
#define LEETCODE_002_INSERT_SORT_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class InsertSort002 {
 public:
  static void insertSort(std::vector<int>& v) {
    for (std::size_t i = 1; i < v.size(); ++i) {
      std::size_t j = i;
      int target = v[j];
      while (j > 0 && SortUtil::less(target, v[j-1]))
        v[j] = v[j-1], --j;
      v[j] = target;
    }
  }
};

}

#endif //LEETCODE_002_INSERT_SORT_HPP
