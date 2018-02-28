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
#include "19_kmp.hpp"
#include "20_horspool.hpp"
#include "GraphUtil.hpp"
#include "21_graph_dfs.hpp"
#include "22_graph_bfs.hpp"
#include "23_graph_cc.hpp"
#include "24_graph_cycle.hpp"
#include "25_graph_twocolor.hpp"
#include "26_directed_dfs.hpp"
#include "DigraphUtil.hpp"
#include "27_diredted_dfs_path.hpp"
#include "28_directed_bfs_path.hpp"
#include "29_directed_cycle.hpp"
#include "30_depth_first_order.hpp"
#include "31_topological.hpp"
#include "32_kosaraju_cc.hpp"
#include "EdgeWeightedGraphUtil.hpp"
#include "33_LazyPrimMST.hpp"
#include "EdgeWeightedDigraphUtil.hpp"
#include "34_prim_mst.hpp"
#include "36_dijkstra.hpp"

using namespace algorithm;

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
  for (const auto &item : v)
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

  in = {2, 4, 1, 5, 7, 6, 1, 9, 0, 2};
  res = FindRepeatElement::findRepeatElement(in);
  EXPECT_TRUE(res == 1 || res == 2);

  in = {0, 0};
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

TEST(kmp, test) {
  using namespace algorithm;

  std::string txt{"bacbababadababacambabacaddababacasdsd"};
  std::string pattern{"ababaca"};

  ssize_t res = KMP::search(pattern, txt);
  EXPECT_EQ(res, 10);
}

TEST(korspool, test) {
  using namespace algorithm;

  std::string txt{"bacbababadababacambabacaddababacasdsd"};
  std::string pattern{"ababaca"};

  ssize_t res = HorspoolSearch::search(txt, pattern);
  EXPECT_EQ(res, 10);
}

TEST(graphutil, test) {
  std::string filename = "../../data/tinyG.txt";
  GraphFactory tinyGraphFactory{filename};
  auto tinyGraph = tinyGraphFactory.genGraph();
  std::cout << tinyGraph->toString() << std::endl;

  filename = "../../data/routes.txt";
  SymbolGraphFactory movieGraphFactory{filename};
  auto movieGraph = movieGraphFactory.genSymbolGraph();
  std::cout << movieGraph->toString() << std::endl;
}

TEST(dfs, test) {
  std::string filename = "../../data/tinyG.txt";
  GraphFactory tinyGraphFactory{filename};
  auto tinyGraph = tinyGraphFactory.genGraph();

  DFS dfs(tinyGraph, 1);
  auto path = dfs.pathTo(5);
  while (!path->empty()) {
    std::cout << std::to_string(path->top()) << " ";
    path->pop();
  }
  std::cout << std::endl;
}

TEST(bfs, test) {
  std::string filename = "../../data/tinyG.txt";
  GraphFactory tinyGraphFactory{filename};
  auto tinyGraph = tinyGraphFactory.genGraph();

  BFS bfs(tinyGraph, 4);
  auto path = bfs.pathTo(1);
  while (!path->empty()) {
    std::cout << std::to_string(path->top()) << " ";
    path->pop();
  }
  std::cout << std::endl;
}

TEST(cc, test) {
  std::string filename = "../../data/tinyG.txt";
  GraphFactory tinyGraphFactory{filename};
  auto tinyGraph = tinyGraphFactory.genGraph();

  CC cc{tinyGraph};
  std::cout << "Count: " << std::to_string(cc.count()) << std::endl;
  EXPECT_EQ(cc.count(), 3);
}

TEST(cycle_twocolor, test) {
  std::string filename = "../../data/tinyG.txt";
  GraphFactory tinyGraphFactory{filename};
  auto tinyGraph = tinyGraphFactory.genGraph();

  Cycle cycle(tinyGraph);
  EXPECT_EQ(true, cycle.hasCycle());

  TwoColor twoColor(tinyGraph);
  EXPECT_EQ(false, twoColor.isTwoColorable());

}

TEST(digraph_util, test) {
  std::string filename{"../../data/tinyDG.txt"};
  DigraphFactory digraphFactory{filename};
  auto digraph = digraphFactory.genDigraph();
  std::cout << digraph->toString() << std::endl;
}

TEST(directed_dfs_path, test) {
  std::string filename{"../../data/tinyDG.txt"};
  DigraphFactory digraphFactory{filename};
  auto digraph = digraphFactory.genDigraph();

  DirectedDFSPath directedDFSPath{digraph, 0};
  auto path = directedDFSPath.pathTo(2);
  while (!path->empty())
    std::cout << path->top() << " ", path->pop();
  std::cout << std::endl;

  DirectedDFSPath directedDFSPath2{digraph, 7};
  path = directedDFSPath2.pathTo(12);
  while (!path->empty())
    std::cout << path->top() << " ", path->pop();
  std::cout << std::endl;

  DirectedBFSPath directedBFSPath{digraph, 0};
  path = directedBFSPath.pathTo(2);
  while (!path->empty())
    std::cout << path->top() << " ", path->pop();
  std::cout << std::endl;

  DirectedBFSPath directedBFSPath2{digraph, 7};
  path = directedBFSPath2.pathTo(12);
  while (!path->empty())
    std::cout << path->top() << " ", path->pop();
  std::cout << std::endl;
}

TEST(direted_cycle, test) {
  std::string filename = "../../data/mediumDG.txt";
  DigraphFactory digraphFactory{filename};
  auto digraph = digraphFactory.genDigraph();

  DirectedCycle cycle{digraph};
  std::stack<int> path = cycle.cycle();
  if (path.empty()) {
    std::cout << "empty path, have no cycle\n";
  } else {
    while (!path.empty())
      std::cout << std::to_string(path.top()) << " ", path.pop();
    std::cout << std::endl;
  }
}

TEST(depth_first_order, test) {
  std::string filename{"../../data/tinyDG.txt"};
  DigraphFactory digraphFactory{filename};
  auto digraph = digraphFactory.genDigraph();

  DepthFirstOrder depthFirstOrder{digraph};
  std::queue<int> pre = depthFirstOrder.pre();
  std::queue<int> post = depthFirstOrder.post();
  std::stack<int> reversePost = depthFirstOrder.reversePost();

  while (!pre.empty())
    std::cout << std::to_string(pre.front()) << " ", pre.pop();
  std::cout << std::endl;

  while (!post.empty())
    std::cout << std::to_string(post.front()) << " ", post.pop();
  std::cout << std::endl;

  while (!reversePost.empty())
    std::cout << std::to_string(reversePost.top()) << " ", reversePost.pop();
  std::cout << std::endl;
}

TEST(kosaraju_cc, test) {
  std::string filename{"../../data/tinyDG.txt"};
  DigraphFactory digraphFactory{filename};
  auto digraph = digraphFactory.genDigraph();

  KosarajuCC cc{digraph};
  std::cout << "kosaraju cc: " << std::to_string(cc.count()) << std::endl;
}

TEST(edge_weighted_graph_util, test) {
  std::string filename{"../../data/tinyEWG.txt"};
  EdgeWeightedGraphFactory factory{filename};
  auto graph = factory.genEdgeWeightedGraph();

  std::cout << graph->toString() << std::endl;
}

TEST(lazy_prim_mst, test) {
  std::string filename{"../../data/tinyEWG.txt"};
  EdgeWeightedGraphFactory factory{filename};
  auto graph = factory.genEdgeWeightedGraph();

  LazyPrimMST lazyPrimMST{graph};
  std::queue<Edge> mst = lazyPrimMST.edges();
  while (!mst.empty()) {
    std::cout << mst.front().toString() << " ";
    mst.pop();
  }
  std::cout << std::endl;
}

TEST(prim_mst, test) {
  std::string filename{"../../data/tinyEWG.txt"};
  EdgeWeightedGraphFactory factory{filename};
  auto graph = factory.genEdgeWeightedGraph();

  PrimMST primMST{graph};
  auto mst = primMST.edges();
  for (const auto &e : mst)
    if (e) std::cout << e->toString() << " ";
  std::cout << std::endl;
}

TEST(edge_weighted_digraph, test) {
  std::string filename = "../../data/tinyEWD.txt";
  EdgeWeightedDigraphFactory factory{filename};
  auto graph = factory.genDigraph();

  std::cout << graph->toString() << std::endl;
}

TEST(dijkstra, test) {
  std::string filename = "../../data/tinyEWD.txt";
  EdgeWeightedDigraphFactory factory{filename};
  auto graph = factory.genDigraph();

  Dijkstra dijkstra{graph, 0};
  std::shared_ptr<std::stack<DirectedEdge>> path = dijkstra.pathTo(6);
  if (path == nullptr)
    std::cout << "can not arrived" << std::endl;
  else {
    while (!path->empty())
      std::cout << path->top().toString() << " ", path->pop();
    std::cout << "weight: " << std::to_string(dijkstra.distTo(6)) << std::endl;
  }
}

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}