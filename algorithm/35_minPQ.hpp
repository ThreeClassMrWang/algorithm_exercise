//
// Created by wcj on 1/30/18.
//

#ifndef LEETCODE_35_MINPQ_HPP
#define LEETCODE_35_MINPQ_HPP

#include <vector>
#include <cstdio>
#include <algorithm>

namespace algorithm {

template<typename T_, typename COMP_>
class MinPQ {
 public:
  MinPQ() : pq_() {
    pq_.push_back(T_());
  }

  std::size_t size() const noexcept { return pq_.size() - 1; }
  bool empty() const noexcept { return size() == 0; }

  T_ pop() {
    T_ top = pq_[1];
    std::swap(pq_[1], pq_[size()]);
    pq_.pop_back();
    sink(1);
    return top;
  }

  template<typename T>
  void change_insert(T &&v) {
    auto it = std::find(pq_.begin() + 1, pq_.end(), v);
    if (it != pq_.end()) {
      *it = v;
      ssize_t index = it - pq_.begin();
      std::swap(pq_[index], pq_[size()]);
    } else {
      pq_.push_back(std::forward<T>(v));
    }
    swim(size());
  }

 private:
  std::vector<T_> pq_;
  COMP_ comp_;

  void swim(ssize_t k) {
    while (k > 1 && comp_(pq_[k / 2], pq_[k]))
      std::swap(pq_[k / 2], pq_[k]), k /= 2;
  }

  void sink(ssize_t k) {
    while (2 * k <= size()) {
      ssize_t j = 2 * k;
      if (j < size() && comp_(pq_[j], pq_[j + 1])) j++;
      if (!comp_(pq_[k], pq_[j])) break;
      std::swap(pq_[k], pq_[j]), k = j;
    }
  }

};

}

#endif //LEETCODE_35_MINPQ_HPP
