//
// Created by wcj on 1/19/18.
//

#ifndef LEETCODE_9_QUICK_SORT_3WAY_HPP
#define LEETCODE_9_QUICK_SORT_3WAY_HPP

#include <vector>
#include <cstdio>
#include "SortUtil.hpp"

namespace algorithm {

class QuickSort3Way {
public:
    static void sort(std::vector<int>& v) {
        sort(v, 0, v.size() - 1);
    }

private:
    static void sort(std::vector<int>& v, ssize_t lo, ssize_t hi) {
        if (lo >= hi) return;

        ssize_t lt = lo, i = lo + 1, gt = hi;
        int target = v[lo];

        while (i <= gt) {
            if (v[i] < target) SortUtil::exch(v[lt++], v[i++]);
            else if (v[i] > target) SortUtil::exch(v[i], v[gt--]);
            else i++;
        }
        sort(v, lo, lt - 1);
        sort(v, gt + 1, hi);
    }
};

}

#endif //LEETCODE_9_QUICK_SORT_3WAY_HPP
