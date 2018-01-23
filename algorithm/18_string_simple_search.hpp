//
// Created by wcj on 1/22/18.
//

#ifndef LEETCODE_18_STRING_SIMPLE_SEARCH_H
#define LEETCODE_18_STRING_SIMPLE_SEARCH_H

#include <string>

namespace algorithm {

class StringSimpleSearch {
public:
    /// 暴力方法1： 直接查找
    ///
    /// \param pat
    /// \param txt
    /// \return
    static ssize_t search(const std::string& pat, const std::string& txt) {
        for (ssize_t i{0}; i <= (ssize_t)txt.size() - (ssize_t)pat.size(); ++i) {
            ssize_t j{0};
            for (; j < pat.size(); ++j)
                if (!pat[j] != txt[i+j]) break;
            if (j == pat.size()) return i;
        }

        return -1;      // Not found
    }

    /// 暴力方法2： 显式回退
    /// 
    /// \param pat
    /// \param txt
    /// \return
    static ssize_t search2(const std::string& pat, const std::string& txt) {
        ssize_t j{0}, M{pat.size()};
        ssize_t i{0}, N{txt.size()};

        for (; i < N && j < M; i++) {
            if (pat[j] == txt[i]) j++;
            else i -= j, j = 0;
        }

        if (j == M) return i - M;
        else return -1;

    }

};

}

#endif //LEETCODE_18_STRING_SIMPLE_SEARCH_H
