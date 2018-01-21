//
// Created by wcj on 17-11-30.
//

#ifndef LEETCODE_6_ZIGZAG_CONVERSION_H
#define LEETCODE_6_ZIGZAG_CONVERSION_H

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include <string>

namespace leetcode {
    class ZigZagConversion {
    public:
        static std::string convert(const std::string &s, int numRows) {
            if (s.empty())
                return std::string("");
            if (numRows == 1)
                return s;
            std::string res(s);
            int resIdx = 0;
            for (int i = 0; i < numRows; ++i) {
                int idx = i;
                int step = (2 * numRows - 2);
                while(idx < s.length()){
                    res[resIdx++] = s[idx];
                    if (i != 0 && i != numRows-1 && idx - 2 * i + step < s.length())
                        res[resIdx++] = s[idx - 2 * i + step];
                    idx += step;
                }
            }
            return res;
        }
    };
}

#endif //LEETCODE_6_ZIGZAG_CONVERSION_H
