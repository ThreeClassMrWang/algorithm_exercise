//
// Created by wcj on 1/19/18.
//

#ifndef LEETCODE_8_QUICK_SORT_ITER_HPP
#define LEETCODE_8_QUICK_SORT_ITER_HPP

#include <cstdio>
#include <vector>
#include "SortUtil.hpp"
#include <stack>

namespace algorithm {

class QuickSortIter {
public:
    static void sort(std::vector<int>& v) {
        sort(v, 0, v.size() - 1);
    }

private:
    static void sort(std::vector<int>& v, ssize_t lo, ssize_t hi) {
        std::stack<std::pair<ssize_t, ssize_t>> stk;
        stk.push(std::pair<ssize_t, ssize_t>(lo, hi));
        while (!stk.empty()) {
            auto range = stk.top();
            if (range.first >= range.second) {
                stk.pop();
            } else {
                auto j = partition(v, range.first, range.second);
                lo = range.first;
                hi = range.second;
                stk.pop();
                stk.push(std::pair<ssize_t, ssize_t>(lo, j - 1));
                stk.push(std::pair<ssize_t, ssize_t>(j + 1, hi));
            }
        }
    }

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

#endif //LEETCODE_8_QUICK_SORT_ITER_HPP
