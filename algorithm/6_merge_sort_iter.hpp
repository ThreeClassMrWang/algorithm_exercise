//
// Created by wcj on 1/18/18.
//

#ifndef LEETCODE_6_MERGE_SORT_ITER_HPP
#define LEETCODE_6_MERGE_SORT_ITER_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class MergeSortIter {
public:
    static void sort(std::vector<int>& v) {
        for(std::size_t sz = 1; sz < v.size(); sz = sz + sz) {
            for (std::size_t lo = 0; lo < v.size() - sz; lo += (sz + sz))
                merge(v, lo, lo + sz - 1, std::min(lo + sz + sz - 1, v.size() - 1));
        }
    }

private:
    static void merge(std::vector<int>& v, std::size_t lo, std::size_t mid, std::size_t hi) {
        static std::vector<int> aux(v.size(), 0);
        for (std::size_t k = lo; k <= hi; ++k)
            aux[k] = v[k];

        std::size_t i = lo, j = mid + 1;
        for (std::size_t k = lo; k <= hi; ++k ) {
            if (i > mid) v[k] = aux[j++];
            else if (j > hi) v[k] = aux[i++];
            else if (SortUtil::less(aux[j], aux[i])) v[k] = aux[j++];
            else v[k] = aux[i++];
        }
    }
};

}

#endif //LEETCODE_6_MERGE_SORT_ITER_HPP
