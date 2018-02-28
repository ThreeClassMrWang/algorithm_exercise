//
// Created by wcj on 1/25/18.
//

#ifndef LEETCODE_51_DEFORM_STRING_HPP
#define LEETCODE_51_DEFORM_STRING_HPP

/// 查看两个词是否为变形词
/// 本题使用字符表的方案

#include <string>
#include <vector>
#include <unordered_map>

namespace interview {

class DeformString {
 public:
  static bool isDeform_1(const std::string &str1, const std::string &str2) {
    // 使用数组充当字符表
    std::vector<std::size_t> str1Char(UINT8_MAX, 0), str2Char(UINT8_MAX, 0);

    for (const auto &c:str1)
      ++str1Char[c];
    for (const auto &c:str2)
      ++str2Char[c];
    return std::equal(str1Char.begin(), str1Char.end(), str2Char.begin());
  }

  /// 使用哈希map
  static bool isDeform_2(const std::string &str1, const std::string &str2) {
    std::unordered_map<char, std::size_t> str1Map, str2Map;

    for (const auto &c : str1)
      ++str1Map[c];
    for (const auto &c : str2)
      ++str2Map[c];

    return (str1Map == str2Map);
  }

};

}

#endif //LEETCODE_51_DEFORM_STRING_HPP
