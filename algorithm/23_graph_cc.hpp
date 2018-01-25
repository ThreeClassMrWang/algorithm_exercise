//
// Created by wcj on 1/25/18.
//

#ifndef LEETCODE_23_GRAPH_CC_HPP
#define LEETCODE_23_GRAPH_CC_HPP

/// 连通分量的求取
#include <vector>
#include "GraphUtil.hpp"

namespace algorithm {

class CC {
public:
    explicit CC(const std::shared_ptr<Graph>& graph) : marked_(graph->V(), false), id_(graph->V(), 0), count_(0), graph_(graph) {
        for (int s = 0; s < graph->V(); ++s) {
            if (!marked_[s]) {
                dfs(s);
                ++count_;
            }
        }
    }

    bool connected(int v, int w) const noexcept {
        return (id_[v] == id_[w]);
    }

    int count() const noexcept {
        return count_;
    }

    int id(int v) const noexcept {
        return id_[v];
    }

private:
    std::vector<bool> marked_;
    std::vector<int> id_;
    int count_;
    std::shared_ptr<Graph> graph_;

    void dfs(int v) {
        marked_[v] = true;
        id_[v] = count_;
        for (const auto& w : graph_->adj(v)) {
            if (!marked_[w])
                dfs(w);
        }
    }

};

}

#endif //LEETCODE_23_GRAPH_CC_HPP
