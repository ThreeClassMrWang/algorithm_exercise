//
// Created by wcj on 1/28/18.
//

#ifndef LEETCODE_18_DIRECTED_BFS_PATH_HPP
#define LEETCODE_18_DIRECTED_BFS_PATH_HPP

/// BFS 路径查找

#include <vector>
#include <stack>
#include <queue>
#include <memory>
#include "DigraphUtil.hpp"

namespace algorithm {

class DirectedBFSPath {
public:
    DirectedBFSPath(const std::shared_ptr<Digraph>& digraph, int start) :
            marked_(digraph->V(), false), edgeTo_(digraph->V(), 0), start_(start), graph_(digraph) {
        bfs(start);
    }

    bool hasPathTo(int v) const noexcept { return marked_[v]; }

    std::shared_ptr<std::stack<int>> pathTo(int v) {
        if (!hasPathTo(v)) return nullptr;

        auto stk {std::make_shared<std::stack<int>>()};

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

    void bfs(int v) {
        std::queue<int> queue;

        queue.push(v);
        marked_[v] = true;

        while (!queue.empty()) {
            int curV = queue.front();
            for (const auto& w : graph_->adj(curV)) {
                if (!marked_[w]) {
                    marked_[w] = true;
                    edgeTo_[w] = curV;
                    queue.push(w);
                }
            }
            queue.pop();
        }
    }

};

}

#endif //LEETCODE_18_DIRECTED_BFS_PATH_HPP
