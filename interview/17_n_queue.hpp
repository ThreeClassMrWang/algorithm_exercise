//
// Created by wcj on 1/25/18.
//

#ifndef LEETCODE_N_QUEUE_HPP
#define LEETCODE_N_QUEUE_HPP

/// N皇后问题
/// N * N 棋盘上摆 N 个皇后，要求任意皇后不同行，不同列，也不在一条斜线上。
/// 给定一个整数 N， 给出有多少种摆法.

/// 解题的思路就是暴力搜索

#include <cstddef>
#include <vector>
#include <algorithm>

namespace interview {

class NQueue {
 public:
  static std::size_t find(std::size_t n) {
    if (n == 0) return 0;
    std::vector<std::size_t> record(n, 0);
    return find(n, record, 0);
  }

 private:
  static std::size_t find(std::size_t n, std::vector<std::size_t> &record, std::size_t i) {
    if (i == n) return 1;

    std::size_t res = 0;
    for (std::size_t k{0}; k < n; ++k) {
      if (isValid(record, i, k)) {
        record[i] = k;
        res += find(n, record, i + 1);
      }
    }

    return res;
  }

  static bool isValid(const std::vector<std::size_t> &record, std::size_t i, std::size_t j) {
    for (std::size_t k{0}; k < i; ++k) {
      /// 这里谨慎使用 std::size_t, 涉及到减法运算这里的类型自动转换就很麻烦
      /// 以后无论如何只使用 ssize_t 切记！！！
      if (j == record[k] || std::abs((ssize_t) i - (ssize_t) k) == std::abs((ssize_t) j - (ssize_t) record[k]))
        return false;
    }

    return true;
  }
};

}

#endif //LEETCODE_N_QUEUE_HPP
