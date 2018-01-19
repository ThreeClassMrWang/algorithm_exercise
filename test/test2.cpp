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
#include "gtest/gtest.h"
#include "SortUtil.hpp"
#include "2_select_sort.hpp"

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
GTEST_API_ int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}