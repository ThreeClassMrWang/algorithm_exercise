//
// Created by wcj on 1/19/18.
//

#ifndef LEETCODE_10_HEAP_SORT_HPP
#define LEETCODE_10_HEAP_SORT_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

class HeapSort {
public:
    static void sort(std::vector<int>& v) {
        int first = v[0];
        v[0] = 0;
        v.push_back(first);
        std::size_t N = v.size() - 1;
        for (std::size_t k = N / 2; k >= 1; --k)
            sink(v, k, N);
        while (N > 1) {
            SortUtil::exch(v[1], v[N--]);
            sink(v, 1, N);
        }
    }

private:
    static void sink(std::vector<int>& v, std::size_t n, std::size_t N) {
        while (2 * n <= N) {
            std::size_t j = 2 * n;
            if (j < N && SortUtil::less(v[j], v[j+1])) j++;
            if (!SortUtil::less(v[n], v[j])) break;
            SortUtil::exch(v[n], v[j]), n = j;
        }
    }
};

}

#endif //LEETCODE_10_HEAP_SORT_HPP
