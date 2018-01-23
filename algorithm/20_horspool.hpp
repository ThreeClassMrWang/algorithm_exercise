//
// Created by wcj on 1/22/18.
//

#ifndef LEETCODE_20_HORSPOOL_HPP
#define LEETCODE_20_HORSPOOL_HPP

/// Boyer-Moore Simple algorithm
/// Horspool algorithm

#include <string>
#include <vector>

namespace algorithm {

class HorspoolSearch {
public:
    static ssize_t search(const std::string& txt, const std::string& pattern) {
        shiftTable(pattern);
        std::size_t i = pattern.size() - 1;
        while (i <= txt.size() - 1) {
            std::size_t k = 0;
            while (k <= pattern.size() - 1 && txt[i - k] == pattern[pattern.size() - 1 - k])
                ++k;
            if (k == pattern.size()) return i - pattern.size() + 1;
            else i += table_[txt[i]];
        }

        return -1;
    }

private:
    static void shiftTable(const std::string& pattern) {
        for (auto& item : table_)
            item = pattern.size();
        for (std::size_t i = 0; i < pattern.size() - 1; ++i)
            table_[pattern[i]] = pattern.size() - 1 - i;
    }

    static std::vector<std::size_t> table_;
};

std::vector<std::size_t > HorspoolSearch::table_(UINT8_MAX, 0);

}

#endif //LEETCODE_20_HORSPOOL_HPP
