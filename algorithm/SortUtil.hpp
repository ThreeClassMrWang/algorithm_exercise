//
// Created by wcj on 1/18/18.
//

#ifndef LEETCODE_SORTUTIL_HPP
#define LEETCODE_SORTUTIL_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <random>

namespace algorithm {

class SortUtil {
public:
    template <typename T>
    static void exch(T& a, T& b) {
        std::swap(a, b);
    }

    template <typename T>
    static bool less(T&& a, T&& b) {
        return (a < b);
    }

    template <typename T>
    static bool checkSorted(const std::vector<T>& v) {
        for (std::size_t i = 1; i < v.size(); ++i) {
            if (less(v[i], v[i-1]))
               return false;
        }

        return true;
    }

    template <typename T>
    static void printVector(const std::vector<T>& v) {
        for (const auto& item : v)
            std::cout << item << " ";
        std::cout << "\n";
    };

    template <std::size_t SIZE>
    static void genRandom(std::vector<int>& v) {
        std::default_random_engine e;
        std::uniform_int_distribution<int> u(0, 10000);

        for (std::size_t i = 0; i < SIZE; ++i)
            v.push_back(u(e));
    }

};

}

#endif //LEETCODE_SORTUTIL_HPP
