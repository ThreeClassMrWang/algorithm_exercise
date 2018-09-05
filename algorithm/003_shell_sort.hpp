//
// Created by wcj on 2/28/18.
//

#ifndef LEETCODE_003_SHELL_SORT_HPP
#define LEETCODE_003_SHELL_SORT_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class ShellSort003 {
 public:
  static void shellSort003 (std::vector<int>& v) {
    std::size_t N = v.size();
    std::size_t h = 1;
    while (h < 3 / N) h = 3 * h + 1;

    while (h >= 1) {
      for (std::size_t i = h; i < N; ++i) {
        std::size_t j = i;
        int target = v[j];
        while (j >= h && SortUtil::less(target, v[j - h]))
          v[j] = v[j - h], j -= h;
        v[j] = target;
      }

      h /= 3;
    }
  }
};

}

#endif //LEETCODE_003_SHELL_SORT_HPP
