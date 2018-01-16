//
// Created by wcj on 1/12/18.
//

#ifndef LEETCODE_1_SEARCH_ARRAY_HPP
#define LEETCODE_1_SEARCH_ARRAY_HPP

//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include <vector>
#include <stdio.h>

namespace offer {

class SearchArray {
public:
    static bool searchArray(int target, std::vector<std::vector<int>> array) {
        if (array.empty() || (!array.empty() && array[0].empty()))
            return false;

        for(const auto& row : array) {
            if (target >= *row.begin() && target <= *(row.end()-1)) {
                ssize_t lo = 0, hi = row.size() - 1;
                while (lo <= hi) {
                    ssize_t mid = lo + (hi - lo) / 2;
                    if (row[mid] == target) return true;
                    else if (row[mid] > target) hi = mid - 1;
                    else lo = mid + 1;
                }
            }
        }

        return false;
    }

};

}

#endif //LEETCODE_1_SEARCH_ARRAY_HPP
