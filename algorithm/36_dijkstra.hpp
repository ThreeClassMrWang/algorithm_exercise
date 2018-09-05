//
// Created by wcj on 1/30/18.
//

#ifndef LEETCODE_16_DIJKSTRA_HPP
#define LEETCODE_16_DIJKSTRA_HPP

/// Dijkstra 路径寻优算法
/// 前提：强连通图，路径权值为正
/// 动态规划的思想

#include <vector>
#include <memory>
#include <stack>
#include "35_minPQ.hpp"
#include "EdgeWeightedDigraphUtil.hpp"

namespace algorithm {

class Dijkstra {
 public:
  Dijkstra(const std::shared_ptr<EdgeWeightedDigraph> &graph, int start) :
      edgeTo_(graph->V(), nullptr), distTo_(graph->V(), std::numeric_limits<double>::max()),
      indexMinPQ_(), graph_(graph), start_(start) {
    distTo_[0] = 0.0;
    indexMinPQ_.change_insert(Entry(0, 0.0));
    while (!indexMinPQ_.empty())
      visit(indexMinPQ_.pop().first);
  }

  bool hasPathTo(int v) const noexcept {
    return distTo_[v] < std::numeric_limits<double>::max();
  }

  std::shared_ptr<std::stack<DirectedEdge>> pathTo(int v) const {
    if (!hasPathTo(v)) return nullptr;
    auto path = std::make_shared<std::stack<DirectedEdge>>();
    for (std::shared_ptr<DirectedEdge> e = edgeTo_[v]; e != nullptr; e = edgeTo_[e->from()])
      path->push(*e);
    return path;
  }

  double distTo(int v) const noexcept {
    return distTo_[v];
  }

 private:
  std::vector<std::shared_ptr<DirectedEdge>> edgeTo_;
  std::vector<double> distTo_;
  using Entry = std::pair<int, double>;
  struct Entry_Greater {
   public:
    bool operator()(const Entry &l, const Entry &r) {
      return (l.second > r.second);
    }
  };
  MinPQ<Entry, Entry_Greater> indexMinPQ_;
  std::shared_ptr<EdgeWeightedDigraph> graph_;
  int start_;

  void visit(int v) {
    for (const auto &e : graph_->adj(v)) {
      int w = e.to();
      if (distTo_[w] > distTo_[v] + e.weight()) {
        distTo_[w] = distTo_[v] + e.weight();
        edgeTo_[w] = std::make_shared<DirectedEdge>(e);
        indexMinPQ_.change_insert(Entry(w, distTo_[w]));
      }
    }
  }

};

}

#endif //LEETCODE_16_DIJKSTRA_HPP
