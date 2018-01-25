//
// Created by wcj on 1/25/18.
//

#ifndef LEETCODE_22_GRAPH_BFS_HPP
#define LEETCODE_22_GRAPH_BFS_HPP

/// 图的广度优先遍历

#include <vector>
#include <queue>
#include <stack>
#include "GraphUtil.hpp"

namespace algorithm {

/// 对于从s可达的任意顶点v，广度优先搜索都能找到一条从s到v的最短路径。

class BFS {
public:
    BFS(const std::shared_ptr<Graph>& graph, int start) : marked_(graph->V(), false), edgeTo_(graph->V(), 0),
        start_(start), graph_(graph) {
        bfs(start_);
    }

    bool hasPathTo(int v) { return marked_[v]; }

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
    std::shared_ptr<Graph> graph_;

    void bfs(int v) {
        std::deque<int> queue;
        marked_[v] = true;

        queue.push_back(v);
        while(!queue.empty()) {
            int curV = queue.front();
            for (const auto& w : graph_->adj(curV)) {
                if (!marked_[w]) {
                    marked_[w] = true;
                    edgeTo_[w] = curV;
                    queue.push_back(w);
                }
            }
            queue.pop_front();
        }
    }
};

}

#endif //LEETCODE_22_GRAPH_BFS_HPP
