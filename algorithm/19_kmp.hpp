//
// Created by wcj on 1/22/18.
//

#ifndef LEETCODE_KMP_H
#define LEETCODE_KMP_H

#include <string>
#include <vector>

// Substring search using kmp
// KMP is recall method

namespace algorithm {

class KMP {
 public:
  static ssize_t search(const std::string &pattern, const std::string &txt) {
    ssize_t N{(ssize_t) txt.size()}, i{0};
    ssize_t M{(ssize_t) pattern.size()}, q{0};
    std::vector<ssize_t> next(pattern.size(), 0);
    get_next(pattern, next);

    for (; i < N; ++i) {
      while (q > 0 && txt[i] != pattern[q])
        q = next[q - 1];
      if (txt[i] == pattern[q]) ++q;
      if (q == M) return (i - M + 1);
    }

    return -1;
  }

 private:
  static void get_next(const std::string &pattern, std::vector<ssize_t> &next) {
    ssize_t M = pattern.size();
    ssize_t q{1}, k{0};
    next[0] = 0;
    for (; q < M; ++q) {
      while (k > 0 && pattern[k] != pattern[q])
        k = next[k - 1];
      if (pattern[k] == pattern[q]) ++k;
      next[q] = k;
    }
  }

};

}

#endif //LEETCODE_KMP_H
