//
// Created by wcj on 1/23/18.
//

#include <7_is_banlance_tree.hpp>
#include "gtest/gtest.h"
#include "354_max_length.hpp"
#include "356_subarray_max_length.hpp"
#include "140_the_sample_structure.hpp"
#include "141_same_struct.hpp"
#include "8_fibonacci.hpp"

using namespace interview;

TEST(max_length, test) {
    std::vector<int> in{1, 2, 1, 1, 1};
    std::size_t res = MaxLengthSubArray::find(in, 3);
    EXPECT_EQ(res, 3);
}

TEST(subarray_max_length, test) {
    std::vector<int> in{1, 2, 1, 1, 1};
    ssize_t res = SubarrayMaxLength::find(in, 3);
    EXPECT_EQ(res, 3);

    in = {1, 2, 3, 3};
    res = SubarrayMaxLength::find(in, 6);
    EXPECT_EQ(res, 3);
}

TEST(the_same_struct, test) {
    std::vector<std::shared_ptr<Node>> nodes;
    for (int i = 0; i <= 10; ++i)
        nodes.emplace_back(std::make_shared<Node>(i));

    nodes[1]->left = nodes[2];
    nodes[1]->right = nodes[3];
    nodes[2]->left = nodes[4];
    nodes[2]->right = nodes[5];
    nodes[4]->right = nodes[8];
    nodes[5]->left = nodes[9];
    nodes[3]->left = nodes[6];
    nodes[3]->right = nodes[7];

    std::vector<std::shared_ptr<Node>> nodes2;
    nodes2.emplace_back(std::make_shared<Node>(2));
    nodes2.emplace_back(std::make_shared<Node>(4));
    nodes2.emplace_back(std::make_shared<Node>(5));
    nodes2.emplace_back(std::make_shared<Node>(8));
    nodes2[0]->left = nodes2[1];
    nodes2[0]->right = nodes2[2];
    nodes2[1]->right = nodes2[3];

    EXPECT_EQ(true, TheSameStruct::contains(nodes[1], nodes2[0]));
}

TEST(same_struct, test) {
    std::vector<std::shared_ptr<Node>> nodes;
    for (int i = 0; i <= 10; ++i)
        nodes.emplace_back(std::make_shared<Node>(i));

    nodes[1]->left = nodes[2];
    nodes[1]->right = nodes[3];
    nodes[2]->left = nodes[4];
    nodes[2]->right = nodes[5];
    nodes[4]->right = nodes[8];
    nodes[5]->left = nodes[9];
    nodes[3]->left = nodes[6];
    nodes[3]->right = nodes[7];

    std::vector<std::shared_ptr<Node>> nodes2;
    nodes2.emplace_back(std::make_shared<Node>(2));
    nodes2.emplace_back(std::make_shared<Node>(4));
    nodes2.emplace_back(std::make_shared<Node>(5));
    nodes2.emplace_back(std::make_shared<Node>(8));
    nodes2[0]->left = nodes2[1];
    nodes2[0]->right = nodes2[2];
    nodes2[1]->right = nodes2[3];

    std::vector<std::shared_ptr<Node>> nodes3;
    nodes3.emplace_back(std::make_shared<Node>(2));
    nodes3.emplace_back(std::make_shared<Node>(4));
    nodes3.emplace_back(std::make_shared<Node>(5));
    nodes3.emplace_back(std::make_shared<Node>(8));
    nodes3.emplace_back(std::make_shared<Node>(9));
    nodes3[0]->left = nodes3[1];
    nodes3[0]->right = nodes3[2];
    nodes3[1]->right = nodes3[3];
    nodes3[2]->left = nodes3[4];

    EXPECT_EQ(true, SameStruct::contains(nodes[1], nodes3[0]));
    EXPECT_EQ(false, SameStruct::contains(nodes[1], nodes2[0]));
}

TEST(balance_tree, test) {
    std::vector<std::shared_ptr<Node>> nodes;
    for (int i = 0; i < 10; ++i)
        nodes.emplace_back(std::make_shared<Node>(i));

    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[1]->left = nodes[3];
    nodes[1]->right = nodes[4];
    nodes[2]->left = nodes[5];
    nodes[2]->right = nodes[6];
    nodes[3]->left = nodes[7];
    nodes[3]->right = nodes[8];
    nodes[4]->left = nodes[9];

    bool res = IsBalanceTree::isBalance(nodes[0]);
    EXPECT_EQ(true, res);

    nodes[2]->left = nullptr;
    nodes[2]->right = nullptr;
    res = IsBalanceTree::isBalance(nodes[0]);
    EXPECT_EQ(false, res);
}

TEST(fabonacci, test) {
    EXPECT_EQ(1, Fibonacci::fibonacci_cur(0));
    EXPECT_EQ(Fibonacci::fibonacci_iter(0), 1);

    EXPECT_EQ(Fibonacci::fibonacci_cur(1), 1);
    EXPECT_EQ(Fibonacci::fibonacci_iter(1), 1);

    EXPECT_EQ(Fibonacci::fibonacci_cur(2), 2);
    EXPECT_EQ(Fibonacci::fibonacci_iter(2), 2);

    EXPECT_EQ(Fibonacci::fibonacci_cur(3), 3);
    EXPECT_EQ(Fibonacci::fibonacci_iter(3), 3);

    EXPECT_EQ(Fibonacci::fibonacci_cur(4), 5);
    EXPECT_EQ(Fibonacci::fibonacci_iter(4), 5);

    EXPECT_EQ(Fibonacci::fibonacci_cur(5), 8);
    EXPECT_EQ(Fibonacci::fibonacci_iter(5), 8);

    EXPECT_EQ(Fibonacci::fibonacci_cur(6), 13);
    EXPECT_EQ(Fibonacci::fibonacci_iter(6), 13);

    EXPECT_EQ(Fibonacci::fibonacci_cur(7), 21);
    EXPECT_EQ(Fibonacci::fibonacci_iter(7), 21);
}

GTEST_API_ int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}