//
// Created by wcj on 1/29/18.
//

#ifndef LEETCODE_33_LAZYPRIMMST_HPP
#define LEETCODE_33_LAZYPRIMMST_HPP

/// 最小生成树的prim实现（延迟）

#include <vector>
#include <queue>
#include <memory>
#include "EdgeWeightedGraphUtil.hpp"

namespace algorithm {

class LazyPrimMST {
 public:
  explicit LazyPrimMST(const std::shared_ptr<EdgeWeightedGraph> &graph) :
      marked_(graph->V(), false), graph_(graph) {
    visit(0);
    while (!minPq_.empty()) {
      Edge e = minPq_.top();
      minPq_.pop();

      int v{e.either()}, w{e.other(v)};
      if (marked_[v] && marked_[w]) continue;
      mst_.push(e);
      if (!marked_[v]) visit(v);
      if (!marked_[w]) visit(w);
    }
  }

  const std::queue<Edge> &edges() const noexcept {
    return mst_;
  }

  double weight() const noexcept {
    double res = 0.0;
    auto mst = mst_;
    while (!mst.empty()) {
      res += mst.front().weight();
      mst.pop();
    }

    return res;
  }

 private:
  std::vector<bool> marked_;
  std::queue<Edge> mst_;
  std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> minPq_;
  std::shared_ptr<EdgeWeightedGraph> graph_;

  void visit(int v) {
    // 标记顶点 v, 并将所有链接 v 和未被标记的顶点的边加入 minPq_
    marked_[v] = true;
    for (const auto &e : graph_->adj(v))
      if (!marked_[e.other(v)]) minPq_.push(e);
  }

};

}

#endif //LEETCODE_33_LAZYPRIMMST_HPP
