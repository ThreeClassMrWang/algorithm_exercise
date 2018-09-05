//
// Created by wcj on 1/29/18.
//

#ifndef LEETCODE_32_KOSARAJU_HPP
#define LEETCODE_32_KOSARAJU_HPP

/// 计算强连通分量

#include <vector>
#include "DigraphUtil.hpp"
#include "30_depth_first_order.hpp"

namespace algorithm {

class KosarajuCC {
 public:
  explicit KosarajuCC(const std::shared_ptr<Digraph> &digraph) :
      order_(digraph->reverse()), marked_(digraph->V(), false), id_(digraph->V(), 0), count_(0), graph_(digraph) {
    auto order = order_.reversePost();
    while (!order.empty()) {
      if (!marked_[order.top()])
        dfs(order.top()), ++count_;
      order.pop();
    }
  }

  bool stronglyConnected(int v, int w) const noexcept {
    return id_[v] == id_[w];
  }

  int id(int v) const noexcept { return id_[v]; }

  int count() const noexcept { return count_; }

 private:
  DepthFirstOrder order_;
  std::vector<bool> marked_;
  std::vector<int> id_;
  int count_;
  std::shared_ptr<Digraph> graph_;

  void dfs(int v) {
    marked_[v] = true;
    id_[v] = count_;
    for (const auto &w : graph_->adj(v))
      if (!marked_[w])
        dfs(w);
  }

};

}

#endif //LEETCODE_32_KOSARAJU_HPP
