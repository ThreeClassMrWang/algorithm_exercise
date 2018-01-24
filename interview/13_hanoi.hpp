//
// Created by wcj on 1/24/18.
//

#ifndef LEETCODE_13_HANOI_HPP
#define LEETCODE_13_HANOI_HPP

/// 汉诺塔问题，递归问题
/// 递推公式： f(n) = 2f(n-1) + 1

#include <string>

namespace interview {

class Hanoi {
public:
    static void move(std::string& out, std::size_t n) {
        Pillar left("left"), mid("mid"), right("right");
        move(out, n, left, mid, right);
    }

private:
    struct Pillar {
        std::string name;

        Pillar(const std::string& n) : name(n) { }
        Pillar(std::string&& n) : name(std::move(n)) { }
    };

    static void move(std::string& out, std::size_t n, const Pillar& left, const Pillar& mid, const Pillar& right) {
        if (n == 0) return;
        if (n == 1) return print(out, n, left, right);

        move(out, n-1, left, right, mid);
        print(out, n, left, right);
        move(out, n-1, mid, left, right);
    }

    static void print(std::string& out, std::size_t n, const Pillar& from, const Pillar& to) {
        out += (std::to_string(n) + ": " + "move from " + from.name + " to " + to.name + "\n");
    }

};

}

#endif //LEETCODE_13_HANOI_HPP
