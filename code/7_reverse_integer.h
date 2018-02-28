//
// Created by wcj on 17-11-14.
//

#ifndef LEETCODE_7_REVERSE_INTEGER_H
#define LEETCODE_7_REVERSE_INTEGER_H

// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
//
// Input: 123
// Output:  321
// Example 2:
//
// Input: -123
// Output: -321
// Example 3:
//
// Input: 120
// Output: 21
// Note:
//
// Assume we are dealing with an environment which could only hold integers
// within the 32-bit signed integer range. For the purpose of this problem,
// assume that your function returns 0 when the reversed integer overflows.

#include <climits>
#include <cstdint>

namespace leetcode {
class ReverseInterger {
 public:
  static int reverse(int x) {
    int64_t res = 0;
    int remains = 0;
    while (x) {
      remains = x % 10;
      res = res * 10 + remains;
      x = (x - remains) / 10;
    }

    if (res > INT_MAX || res < INT_MIN)
      return 0;
    else
      return (int) res;
  }
};
}

#endif // LEETCODE_7_REVERSE_INTEGER_H
