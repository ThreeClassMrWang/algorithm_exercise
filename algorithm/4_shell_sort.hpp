//
// Created by wcj on 1/18/18.
//

#ifndef LEETCODE_4_SHELL_SORT_HPP
#define LEETCODE_4_SHELL_SORT_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class ShellSort {
public:
    static void sort(std::vector<int>& v) {
        std::size_t N = v.size();
        std::size_t h = 1;
        while (h < N/3) h = h << 1 + h + 1;
        while (h >= 1)  {
            for (std::size_t i = h; i < N; ++i) {
                std::size_t j = i;
                int target = v[i];
                while (j >= h && (j -= h, SortUtil::less(target, v[j])))
                    v[j+h] = v[j];
                v[j] = target;
            }
            h /= 3;
        }
    }
};

}

#endif //LEETCODE_4_SHELL_SORT_HPP
