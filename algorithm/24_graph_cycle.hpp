//
// Created by wcj on 1/25/18.
//

#ifndef LEETCODE_24_GRAPH_CYCLE_HPP
#define LEETCODE_24_GRAPH_CYCLE_HPP

/// 图是否是无环图

#include <vector>
#include "GraphUtil.hpp"

namespace algorithm {

/// 注意需要记录出发点的位置，因为回溯时会再次回到出发点
/// 如果检测到某点已经访问到，并且其不是出发点，则存在环
class Cycle {
 public:
  explicit Cycle(const std::shared_ptr<Graph> &graph) :
      marked_(graph->V(), false), cycled_(false), graph_(graph) {
    for (int s{0}; s < graph->V(); ++s)
      if (!marked_[s])
        dfs(s, s);
  }

  bool hasCycle() const noexcept { return cycled_; }

 private:
  std::vector<bool> marked_;
  bool cycled_;
  std::shared_ptr<Graph> graph_;

  void dfs(int v, int u) {
    marked_[v] = true;
    for (const auto &w : graph_->adj(v)) {
      if (!marked_[w])
        dfs(w, u);
      else if (u != w)
        cycled_ = true;
    }
  }
};

}

#endif //LEETCODE_24_GRAPH_CYCLE_HPP
