//
// Created by wcj on 1/9/18.
//

#include <iostream>
#include <memory>
#include <cstdlib>

class Node {
public:
    int value_;
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> right_;

    Node(int value) : value_(value), left_(nullptr), right_(nullptr) { }
};

bool findMaxSearchTree(std::shared_ptr<Node> head, int& max, std::shared_ptr<Node>& target) {
    if (!head) {
        max = 0;
        return true;
    }

    int leftMax, rightMax;
    bool leftIsSearch = findMaxSearchTree(head->left_, leftMax, target);
    bool rightIsSearch = findMaxSearchTree(head->right_, rightMax, target);

    bool res = false;
    if (leftIsSearch && rightIsSearch) {
        if ((!head->left_ && head->right_ && head->value_ <= head->right_->value_) ||
                (head->left_ && !head->right_ && head->left_->value_ <= head->value_) ||
                (head->left_ && head->right_ && head->left_->value_ <= head->value_ <= head->right_->value_) ||
                (!head->left_ && !head->right_)) {
            max = leftMax + rightMax + 1;
            target = head;
            res = true;
        }
    }
    return res;
}

int getHeight(std::shared_ptr<Node> node, int h) {
    if (!node) return h;
    return std::max(getHeight(node->left_, h + 1), getHeight(node->right_, h + 1));
}

bool isBanlance(std::shared_ptr<Node> node) {
    if (!node) true;

    if (std::abs(getHeight(node->left_, 0) - getHeight(node->right_, 0)) > 1)
        return false;
    else
        return true;
}

int main(int, char**) {
    std::shared_ptr<Node> root = std::make_shared<Node>(6);
    std::shared_ptr<Node> node1  = std::make_shared<Node>(1),
            node2 = std::make_shared<Node>(12),
            node3 = std::make_shared<Node>(0),
            node4 = std::make_shared<Node>(3),
            node5 = std::make_shared<Node>(10),
            node6 = std::make_shared<Node>(13),
            node7 = std::make_shared<Node>(4),
            node8 = std::make_shared<Node>(14),
            node9 = std::make_shared<Node>(20),
            node10 = std::make_shared<Node>(16),
            node11 = std::make_shared<Node>(2),
            node12 = std::make_shared<Node>(5),
            node13 = std::make_shared<Node>(11),
            node14 = std::make_shared<Node>(15);
    root->left_ = node1;
    root->right_ = node2;
    node1->left_ = node3;
    node1->right_ = node4;
    node2->left_ = node5;
    node2->right_ = node6;
    node5->left_ = node7;
    node5->right_ = node8;
    node6->left_ = node9;
    node6->right_ = node10;
    node7->left_ = node11;
    node7->right_ = node12;
    node8->left_ = node13;
    node8->right_ = node14;

    int max;
    std::shared_ptr<Node> target;
    findMaxSearchTree(root, max, target);
    std::cout << "Max:" << max << " target:" << target->value_ << std::endl;

    std::cout << "isBalance: " << isBanlance(node5) << std::endl;
}
