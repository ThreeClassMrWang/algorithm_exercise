//
// Created by wcj on 1/20/18.
//

#ifndef LEETCODE_14_SELECT_K_HPP
#define LEETCODE_14_SELECT_K_HPP

#include <cstdio>
#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class SelectK {
public:
    static int select(std::vector<int>& v, size_t k) {
        ssize_t lo = 0, hi = v.size() - 1;
        while (hi > lo) {
            ssize_t j = partition(v, lo, hi);
            if (j == k) return v[k];
            else if (j > k) hi = j - 1;
            else lo = j + 1;
        }
        return v[k];
    }

private:
    static ssize_t partition(std::vector<int>& v, ssize_t lo, ssize_t hi) {
        int target = v[lo];
        ssize_t i = lo, j = hi + 1;
        while (true) {
            while (SortUtil::less(v[++i], target)) if (i == hi) break;
            while (SortUtil::less(target, v[--j])) if (j == lo) break;
            if (i >= j) break;
            SortUtil::exch(v[i], v[j]);
        }
        SortUtil::exch(v[lo], v[j]);

        return j;
    }
};

}

#endif //LEETCODE_14_SELECT_K_HPP
