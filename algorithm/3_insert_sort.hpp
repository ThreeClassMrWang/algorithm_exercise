//
// Created by wcj on 1/18/18.
//

#ifndef LEETCODE_3_INSERT_SORT_HPP
#define LEETCODE_3_INSERT_SORT_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class InsertSort {
public:
    static void sort(std::vector<int>& v) {
        std::size_t N = v.size();
        for (std::size_t i = 1; i < N; ++i) {
            std::size_t j = i;
            int target = v[i];
            while (j > 0 && SortUtil::less(target, v[--j]))
                v[j+1] = v[j];
            v[j] = target;
        }
    }
};

}

#endif //LEETCODE_3_INSERT_SORT_HPP
