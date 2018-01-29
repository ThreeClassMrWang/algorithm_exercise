//
// Created by wcj on 1/28/18.
//

#ifndef LEETCODE_19_DIRECTED_CYCLE_HPP
#define LEETCODE_19_DIRECTED_CYCLE_HPP

/// 查看有向图是否存在环

#include <vector>
#include <stack>
#include "DigraphUtil.hpp"

namespace algorithm {

class DirectedCycle {
public:
    explicit DirectedCycle(const std::shared_ptr<Digraph>& graph) :
            marked_(graph->V(), false), edgeTo_(graph->V(), 0), cycle_(),
            onStack_(graph->V(), false), graph_(graph) {
        for (int v{0}; v < graph->V(); ++v)
            if (!marked_[v])
                dfs(v);
    }

    bool hasCycle() const noexcept { return !cycle_.empty(); }

    const std::stack<int>& cycle() const noexcept { return cycle_; }

private:
    std::vector<bool> marked_;
    std::vector<int> edgeTo_;
    std::stack<int> cycle_;
    std::vector<bool> onStack_;
    std::shared_ptr<Digraph> graph_;

    void dfs(int v) {
        onStack_[v] = true;
        marked_[v] = true;

        for (const auto& w : graph_->adj(v)) {
            if (hasCycle()) return;
            else if (!marked_[w]) {
                edgeTo_[w] = v;
                dfs(w);
            } else if (onStack_[w]) {
                for (int x = v; x != w; ++x)
                    cycle_.push(x);
                cycle_.push(w);
                cycle_.push(v);
            }
        }

        onStack_[v] = false;
    }
};

}

#endif //LEETCODE_19_DIRECTED_CYCLE_HPP
