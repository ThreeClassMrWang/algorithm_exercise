//
// Created by wcj on 1/23/18.
//

#include <7_is_banlance_tree.hpp>
#include <15_max_public_substring.hpp>
#include "gtest/gtest.h"
#include "354_max_length.hpp"
#include "356_subarray_max_length.hpp"
#include "140_the_sample_structure.hpp"
#include "141_same_struct.hpp"
#include "8_fibonacci.hpp"
#include "9_min_path.hpp"
#include "10_min_money.hpp"
#include "11_money_method.hpp"
#include "12_max_increase_subarray.hpp"
#include "13_hanoi.hpp"
#include "14_max_public_subarray.hpp"
#include "15_max_public_substring.hpp"
#include "16_min_edit_cost.hpp"

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

TEST(min_path, test) {
    std::vector<std::vector<int>> in;
    int res;

    in = {{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
    res = MinPath::find(in);
    EXPECT_EQ(res, 12);

    res = MinPath::find_op(in);
    EXPECT_EQ(res, 12);
}

TEST(min_money, test) {
    std::vector<int> arr;
    int aim, res;

    arr = {5, 2, 3};
    aim = 20;
    res = MinMoney::find1(arr, aim);
    EXPECT_EQ(res, 4);

    aim = 0;
    res = MinMoney::find1(arr, aim);
    EXPECT_EQ(res, 0);

    arr = {3, 5};
    aim = 2;
    res = MinMoney::find1(arr, aim);
    EXPECT_EQ(res, -1);

    arr = {5, 2, 3};
    aim = 20;
    res = MinMoney::find1_op(arr, aim);
    EXPECT_EQ(res, 4);

    aim = 0;
    res = MinMoney::find1_op(arr, aim);
    EXPECT_EQ(res, 0);

    arr = {3, 5};
    aim = 2;
    res = MinMoney::find1_op(arr, aim);
    EXPECT_EQ(res, -1);

    arr = {5, 2, 3};
    aim = 20;
    res = MinMoney::find2(arr, aim);
    EXPECT_EQ(res, -1);

    arr = {5, 2, 5, 3};
    aim = 10;
    res = MinMoney::find2(arr, aim);
    EXPECT_EQ(res, 2);

    aim = 15;
    res = MinMoney::find2(arr, aim);
    EXPECT_EQ(res, 4);

    aim = 0;
    res = MinMoney::find2(arr, aim);
    EXPECT_EQ(res, 0);

    arr = {5, 10, 25, 1};
    aim = 0;
    res = MoneyMethod::find(arr, aim);
    EXPECT_EQ(res, 1);

    aim = 15;
    res = MoneyMethod::find(arr, aim);
    EXPECT_EQ(res, 6);

    arr = {3, 5};
    aim = 2;
    res = MoneyMethod::find(arr, aim);
    EXPECT_EQ(res, 0);

    arr = {5, 10, 25, 1};
    aim = 0;
    res = MoneyMethod::find_op(arr, aim);
    EXPECT_EQ(res, 1);

    aim = 15;
    res = MoneyMethod::find_op(arr, aim);
    EXPECT_EQ(res, 6);

    arr = {3, 5};
    aim = 2;
    res = MoneyMethod::find_op(arr, aim);
    EXPECT_EQ(res, 0);
}

TEST(max_increase_subarray, test) {
    std::vector<int> arr, res, expect;

    arr = {2,1,5,3,6,4,8,9,7};
    res = MaxIncreaseSubArray::find(arr);
    expect = {1,3,4,8,9};
    EXPECT_EQ(res, expect);

    res = MaxIncreaseSubArray::find(arr);
    EXPECT_EQ(res, expect);
}

TEST(hanoi, test) {
    std::string out;
    Hanoi::move(out, 1);
    out += "+++++++++++++\n";
    Hanoi::move(out, 2);
    out += "+++++++++++++\n";
    Hanoi::move(out, 3);
    out += "+++++++++++++\n";

}

TEST(max_public_sub_array, test) {
    std::string str1, str2, res;

    str1 = "1A2C3D4B56";
    str2 = "B1D23CA45B6A";
    res = MaxPublicSubArray::find(str1, str2);
    EXPECT_EQ(true, res == std::string("123456") || res == std::string("12C4B6"));
}

TEST(max_public_substring, test) {
    std::string str1, str2, res;

    str1 = "1AB2345CD";
    str2 = "12345EF";
    res = MaxPublicSubString::find(str1, str2);
    EXPECT_EQ(res, std::string("2345"));
}

TEST(min_edit_cost, test) {
    std::string str1, str2;
    std::size_t res;

    str1 = "abc";
    str2 = "adc";
    res = MinEditCost::cost(str1, str2, 5, 3, 2);
    EXPECT_EQ(res, 2);

    res = MinEditCost::cost(str1, str2, 5, 3, 100);
    EXPECT_EQ(res, 8);

    str2 = "abc";
    res = MinEditCost::cost(str1, str2, 5, 3, 2);
    EXPECT_EQ(res, 0);
}

GTEST_API_ int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}