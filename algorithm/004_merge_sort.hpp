//
// Created by wcj on 2/28/18.
//

#ifndef LEETCODE_004_MERGE_SORT_HPP
#define LEETCODE_004_MERGE_SORT_HPP

#include <vector>
#include <memory>
#include "SortUtil.hpp"

namespace algorithm {

class MergeSort004 {
 public:
  static void mergeSort(std::vector<int>& v) {
    if (v.empty())
      return;

    std::shared_ptr<std::vector<int>> paux = std::make_shared<std::vector<int>>(v);
    mergeSort(v, 0, v.size() - 1, *paux);
  }

  static void mergeSort2(std::vector<int>& v) {
    if (v.empty()) return;

    auto aux = std::make_shared<std::vector<int>>(v);
    std::size_t N = v.size();

    for (std::size_t sz = 1; sz < N; sz = sz + sz) {
      for (std::size_t lo = 0; lo < N - sz; lo += (sz + sz))
        merge(v, lo, lo + sz -1, std::min(lo + sz + sz - 1, N - 1), *aux);
    }
  }

 private:

  static void mergeSort(std::vector<int>& v, std::size_t lo, std::size_t hi, std::vector<int>& aux) {
    if (lo >= hi) return;
    std::size_t mid = lo + (hi - lo) / 2;
    mergeSort(v, lo, mid, aux);
    mergeSort(v, mid + 1, hi, aux);
    merge(v, lo, mid, hi, aux);
  }

  static void merge(std::vector<int>& v, std::size_t lo, std::size_t mid, std::size_t hi, std::vector<int>& aux) {
    std::size_t i = lo, j = mid + 1;

    for (std::size_t k =lo; k <= hi; ++k) aux[k] = v[k];

    for (std::size_t k = lo; k <= hi; ++k) {
      if (i > mid) v[k] = aux[j++];
      else if (j > hi) v[k] = aux[i++];
      else if (SortUtil::less(aux[i], aux[j])) v[k] = aux[i++];
      else v[k] = aux[j++];
    }

  }


};

}

#endif //LEETCODE_004_MERGE_SORT_HPP
