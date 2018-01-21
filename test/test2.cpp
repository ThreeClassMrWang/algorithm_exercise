//
// Created by wcj on 1/16/18.
//

#include <3_insert_sort.hpp>
#include <4_shell_sort.hpp>
#include <5_merge_sort.hpp>
#include <6_merge_sort_iter.hpp>
#include <7_quick_sort.hpp>
#include <8_quick_sort_iter.hpp>
#include <9_quick_sort_3way.hpp>
#include <11_MaxPQ.hpp>
#include <10_heap_sort.hpp>
#include <15_binary_search.hpp>
#include "gtest/gtest.h"
#include "SortUtil.hpp"
#include "2_select_sort.hpp"
#include "12_find_repeat_element.hpp"
#include "13_kandall_distance.hpp"
#include "14_select_k.hpp"

TEST(sort, test) {
    using namespace algorithm;

    std::vector<int> v;
    algorithm::SortUtil::genRandom<100>(v);

    algorithm::SelectSort::sort(v);
    EXPECT_EQ(true, algorithm::SortUtil::checkSorted(v));

    v.clear();
    algorithm::SortUtil::genRandom<100>(v);
    InsertSort::sort(v);
    EXPECT_EQ(true, SortUtil::checkSorted(v));

    v.clear();
    algorithm::SortUtil::genRandom<100>(v);
    ShellSort::sort(v);
    EXPECT_EQ(true, SortUtil::checkSorted(v));

    v.clear();
    algorithm::SortUtil::genRandom<100>(v);
    MergeSort::sort(v);
    EXPECT_EQ(true, SortUtil::checkSorted(v));

    v.clear();
    algorithm::SortUtil::genRandom<100>(v);
    MergeSortIter::sort(v);
    EXPECT_EQ(true, SortUtil::checkSorted(v));

    v.clear();
    SortUtil::genRandom<100>(v);
    QuickSort::sort(v);
    EXPECT_EQ(true, SortUtil::checkSorted(v));

    v.clear();
    SortUtil::genRandom<100>(v);
    QuickSortIter::sort(v);
    EXPECT_EQ(true, SortUtil::checkSorted(v));

    v.clear();
    SortUtil::genRandom<100>(v);
    QuickSort3Way::sort(v);
    EXPECT_EQ(true, SortUtil::checkSorted(v));

    v.clear();
    SortUtil::genRandom<100>(v);
    HeapSort::sort(v);
    EXPECT_EQ(true, SortUtil::checkSorted(v));
    EXPECT_EQ(101, v.size());
}

TEST(MaxPQ, test) {
    using namespace algorithm;

    std::vector<int> v;
    SortUtil::genRandom<100>(v);

    MaxPQ<int> pq;
    for (const auto& item : v)
        pq.insert(item);

    for (ssize_t i = v.size() - 1; i >= 0; --i) {
        v[i] = pq.delMax();
    }
    EXPECT_EQ(true, SortUtil::checkSorted(v));
}

TEST(find_repeat_element, test) {
    using namespace algorithm;

    std::vector<int> in;
    int res;

    in = {2,4,1,5,7,6,1,9,0,2};
    res = FindRepeatElement::findRepeatElement(in);
    EXPECT_TRUE(res == 1 | res == 2);

    in = {0 , 0};
    res = FindRepeatElement::findRepeatElement(in);
    EXPECT_EQ(res, 0);

    in.clear();
    for (int i = 1; i <= 1000; ++i)
        in.push_back(i);
    in.push_back(253);
    res = FindRepeatElement::findUniqueNumber_1(in);
    EXPECT_EQ(res, 253);
    res = FindRepeatElement::findUniqueNumber_2(in);
    EXPECT_EQ(res, 253);
}

TEST(kandall_distance, test) {
    using namespace algorithm;

    std::vector<int> a;
    std::vector<int> b;
    int res;

    a = {0, 3, 1, 6, 2, 5, 4};
    b = {1, 0, 3, 6, 4, 2, 5};
    res = KandallDistance::calcutate(a, b);
    EXPECT_EQ(res, 4);

    a = {1, 2, 3, 4, 5};
    b = {3, 4, 1, 2, 5};
    res = KandallDistance::calcutate(a, b);
    EXPECT_EQ(res, 4);

    a = {0, 3, 2, 4, 1};
    b = {4, 0, 3, 2, 1};
    res = KandallDistance::calcutate(a, b);
    EXPECT_EQ(res, 3);

    a = {1, 2, 3, 4, 5};
    b = {1, 2, 3, 4, 5};
    res = KandallDistance::calcutate(a, b);
    EXPECT_EQ(res, 0);
}

TEST(select_k, test) {
    using namespace algorithm;

    std::vector<int> in;
    int res;

    in = {0, 3, 1, 6, 2, 5, 4};
    res = SelectK::select(in, 2);
    EXPECT_EQ(res, 2);

    std::sort(in.begin(), in.end());
    EXPECT_EQ(1, BinarySearch::search(in, 1));
}

GTEST_API_ int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}