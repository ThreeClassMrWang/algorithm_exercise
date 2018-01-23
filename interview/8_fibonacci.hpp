//
// Created by wcj on 1/23/18.
//

#ifndef LEETCODE_8_FIBONACCI_HPP
#define LEETCODE_8_FIBONACCI_HPP

#include <cstddef>

namespace interview {

class Fibonacci {
public:
    static std::size_t fibonacci_cur(std::size_t n) {
        if (n == 0 || n == 1) return 1;
        return fibonacci_cur(2, 1, 1, n);
    }

    static std::size_t fibonacci_iter(std::size_t n) {
        if (n == 0 || n == 1) return 1;

        std::size_t f_1{1}, f_2{1}, f{0};
        std::size_t k{1};
        while (++k <= n)
            f = f_1 + f_2, f_2 = f_1, f_1 = f;

        return f;
    }

private:
    static std::size_t fibonacci_cur(std::size_t k, std::size_t f_1, std::size_t f_2, std::size_t n) {
        if (k == n) return f_1 + f_2;
        return fibonacci_cur(k + 1, f_1 + f_2, f_1, n);     // CPS
    }



};

}

#endif //LEETCODE_8_FIBONACCI_HPP
