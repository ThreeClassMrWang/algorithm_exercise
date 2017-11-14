//
// Created by wcj on 17-11-14.
//

#ifndef LEETCODE_7_REVERSE_INTEGER_H
#define LEETCODE_7_REVERSE_INTEGER_H

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
                return  0;
            else
                return (int)res;
        }
    };
}

#endif //LEETCODE_7_REVERSE_INTEGER_H
