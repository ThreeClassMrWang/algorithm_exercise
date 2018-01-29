//
// Created by wcj on 1/26/18.
//

#ifndef LEETCODE_27_DIREDTED_DFS_PATH_HPP
#define LEETCODE_27_DIREDTED_DFS_PATH_HPP

/// 寻找有向图中dfs搜索的路径

#include <vector>
#include <stack>
#include "DigraphUtil.hpp"

namespace algorithm {

class DirectedDFSPath {
public:
    DirectedDFSPath(const std::shared_ptr<Digraph>& graph, int start) :
            marked_(graph->V(), false), edgeTo_(graph->V(), 0), start_(start), graph_(graph) {
        dfs(start);
    }

    bool hasPathTo(int v) const noexcept {
        return marked_[v];
    }

    std::shared_ptr<std::stack<int>> pathTo(int v) {
        if (!marked_[v]) return nullptr;

        auto stk = std::make_shared<std::stack<int>>();
        for (; v != start_; v = edgeTo_[v])
            stk->push(v);
        stk->push(start_);
        return stk;
    }

private:
    std::vector<bool> marked_;
    std::vector<int> edgeTo_;
    int start_;
    std::shared_ptr<Digraph> graph_;

    void dfs(int v) {
        marked_[v] = true;
        for (const auto& w : graph_->adj(v)) {
            if (!marked_[w]) {
                edgeTo_[w] = v;
                dfs(w);
            }
        }
    }
};

}

#endif //LEETCODE_27_DIREDTED_DFS_PATH_HPP
