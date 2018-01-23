//
// Created by wcj on 1/23/18.
//

#ifndef LEETCODE_NODE_HPP
#define LEETCODE_NODE_HPP

#include <memory>

namespace interview {

struct Node {
    int value;
    std::shared_ptr<Node> left, right;

    Node(int v) : value(v), left(nullptr), right(nullptr) { }
};

}

#endif //LEETCODE_NODE_HPP
