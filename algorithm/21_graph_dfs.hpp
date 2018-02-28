//
// Created by wcj on 1/25/18.
//

#ifndef LEETCODE_21_GRAPH_DFS_HPP
#define LEETCODE_21_GRAPH_DFS_HPP

/// 图的深度优先搜索

#include "GraphUtil.hpp"
#include <stack>

namespace algorithm {

class DFS {
 public:
  DFS(const std::shared_ptr<Graph> &graph, int start) : marked_(graph->V(), false), edgeTo_(graph->V(), 0),
                                                        start_(start), graph_(graph) {
    dfs(start);
  }

  bool hasPathTo(int v) const noexcept {
    return marked_[v];
  }

  std::shared_ptr<std::stack<int>> pathTo(int v) {
    if (!hasPathTo(v)) return nullptr;

    auto stk{std::make_shared<std::stack<int>>()};
    for (; v != start_; v = edgeTo_[v])
      stk->push(v);
    stk->push(start_);
    return stk;
  }

 private:
  std::vector<bool> marked_;
  std::vector<int> edgeTo_;
  int start_;
  const std::shared_ptr<Graph> graph_;

  void dfs(int v) {
    marked_[v] = true;
    for (const auto &w : graph_->adj(v))
      if (!marked_[w]) {
        edgeTo_[w] = v;
        dfs(w);
      }
  }
};

}

#endif //LEETCODE_21_GRAPH_DFS_HPP
