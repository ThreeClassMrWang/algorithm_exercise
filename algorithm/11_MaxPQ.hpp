//
// Created by wcj on 1/19/18.
//

#ifndef LEETCODE_11_MAXPQ_HPP
#define LEETCODE_11_MAXPQ_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

template <typename T>
class MaxPQ {
public:
    std::size_t size() const noexcept { return pq.size() - 1; }
    bool empty() const noexcept { return (size() == 0); }

    void insert(const T& v) {
        pq.push_back(v);
        swim(size());
    }

    void insert(T&& v) {
        pq.emplace_back(v);
        swim(size());
    }

    T delMax() {
        T max = pq[1];
        SortUtil::exch(pq[1], pq[size()]);
        pq.pop_back();
        sink(1);
        return max;
    }

private:
    std::vector<T> pq{T()};

    void swim(std::size_t n) {
        while (n  > 1 && SortUtil::less(pq[n/2], pq[n]))
            SortUtil::exch(pq[n/2], pq[n]), n /= 2;
    }

    void sink(std::size_t n) {
        while (2 * n <= size()) {
            std::size_t j = 2 * n;
            if (j < size() && SortUtil::less(pq[j], pq[j+1])) j++;
            if (!SortUtil::less(pq[n], pq[j])) break;
            SortUtil::exch(pq[n], pq[j]), n = j;
        }
    }
};

}

#endif //LEETCODE_11_MAXPQ_HPP
