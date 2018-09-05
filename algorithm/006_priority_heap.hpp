//
// Created by wcj on 3/1/18.
//

#ifndef LEETCODE_006_PRIORITY_HEAP_HPP
#define LEETCODE_006_PRIORITY_HEAP_HPP

// 堆的实现

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

template <typename T, typename COMPARE = std::less<T>>
class PriorityHeapSort006 {
 public:
  PriorityHeapSort006() { pq_.push_back(T()); }

  std::size_t size() const noexcept { return (pq_.size() - 1); }
  bool empty() const noexcept { return size() == 0; }

  template <typename T_>
  void insert(T_&& t) {
    pq_.push_back(std::forward<T_>(t));
    swim(size());
  }

  const T& top() const {
    if (empty()) throw std::length_error("priority queue is empty");
    return pq_[1];
  }

  void pop() {
    if (empty()) throw std::length_error("priority queue is empty");
    std::swap(pq_[1], pq_[size()]);
    pq_.pop_back();
    sink(1);
  }

  template <typename T_>
  void pop_and_insert(T_&& t) {
    pq_[1] = std::forward<T_>(t);
    sink(1);
  }

 private:
  std::vector<T> pq_;
  COMPARE cmp_;

  void swim(ssize_t k) {
    while (k > 1 && cmp_(pq_[k/2], pq_[k])) {
      std::swap(pq_[k/2], pq_[k]);
      k /= 2;
    }
  }

  void sink(ssize_t k) {
    while (2 * k <= size()) {
      ssize_t j = 2 * k;
      if (j < size() && cmp_(pq_[j], pq_[j + 1])) ++j;
      if (!cmp_(pq_[k], pq_[j])) break;
      std::swap(pq_[j], pq_[k]);
      k = j;
    }
  }

};

}

#endif //LEETCODE_006_PRIORITY_HEAP_HPP
