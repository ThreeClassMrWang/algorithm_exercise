//
// Created by wcj on 3/3/18.
//

#ifndef LEETCODE_2_CHAR_COUNT_HPP
#define LEETCODE_2_CHAR_COUNT_HPP

//题目描述
//    写出一个程序，接受一个有字母和数字以及空格组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
//
//输入描述:
//    输入一个有字母和数字以及空格组成的字符串，和一个字符。
//
//输出描述:
//    输出输入字符串中含有该字符的个数。
//
//示例1
//    输入
//ABCDEF A
//输出
//1

#include <vector>
#include <string>

namespace huawei {

class CharCount {
 public:
  static std::size_t count(const std::string& str, const char c) {
    std::size_t cnt = 0;
    for (const auto& i : str) {
      if (equal(i, c)) ++cnt;
    }

    return cnt;
  }

 private:
  static inline bool equal(const char a, const char b) {
    if ((a >= 'A' && a <= 'Z') && (b >= 'a' && b <= 'z')) {
      return ((a - 'A' + 'a') == b);
    } else if ((a >= 'a' && b <= 'z') && (b >= 'A' && b <= 'Z')) {
      return (a == (b - 'A' + 'a'));
    } else {
      return a == b;
    }
  }
};

}

#endif //LEETCODE_2_CHAR_COUNT_HPP
