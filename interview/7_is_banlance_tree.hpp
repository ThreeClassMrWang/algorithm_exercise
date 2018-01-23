//
// Created by wcj on 1/23/18.
//

#ifndef LEETCODE_7_IS_BANLANCE_TREE_HPP
#define LEETCODE_7_IS_BANLANCE_TREE_HPP

/// 判断一棵树是否是平衡二叉树

#include "node.hpp"
#include <algorithm>

namespace interview {

class IsBalanceTree {
public:
    static bool isBalance(const std::shared_ptr<Node>& node) {
        bool res = true;
        (void)height(node, res);
        return res;
    }

private:
    static ssize_t height(const std::shared_ptr<Node>& node, bool& res) {
        if (node == nullptr) return 0;
        ssize_t lheight = height(node->left, res);
        if (!res) return 0;
        ssize_t rheight = height(node->right, res);
        if (!res) return 0;

        if (std::abs(lheight - rheight) > 1)
            res = false;

        ssize_t h = std::max(lheight, rheight) + 1;
        return h;
    }
};

}

#endif //LEETCODE_7_IS_BANLANCE_TREE_HPP
