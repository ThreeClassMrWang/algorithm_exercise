//
// Created by wcj on 17-12-1.
//

#ifndef LEETCODE_12_INTEGER_TO_ROMAN_H
#define LEETCODE_12_INTEGER_TO_ROMAN_H

//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.

#include <string>
#include <sstream>

namespace leetcode {
    class IntegerToRoman {
    public:
        static std::string intToRoman(int num) {
            std::stringstream ss;
            ss << v1[num / 1000] << v2[(num % 1000) / 100] << v3[(num % 100) / 10] << v4[num % 10];
            return ss.str();
        }

    private:
        static std::vector<std::string> v1;
        static std::vector<std::string> v2;
        static std::vector<std::string> v3;
        static std::vector<std::string> v4;
    };

    std::vector<std::string> IntegerToRoman::v1{"", "M", "MM", "MMM"};
    std::vector<std::string> IntegerToRoman::v2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    std::vector<std::string> IntegerToRoman::v3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    std::vector<std::string> IntegerToRoman::v4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
}

#endif //LEETCODE_12_INTEGER_TO_ROMAN_H
