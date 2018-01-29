//
// Created by wcj on 1/26/18.
//

#ifndef LEETCODE_DIRECTEDDFS_HPP
#define LEETCODE_DIRECTEDDFS_HPP

/// 有方向的深度优先检测

#include <vector>
#include "DigraphUtil.hpp"

namespace algorithm {

class DirectedDFS {
public:
    explicit DirectedDFS(int s) {
        dfs(s);
    }

    explicit DirectedDFS(const std::vector<int>& sources) {
        for (const auto& s : sources)
            dfs(s);
    }

    bool marked(int v) {
        return marked_[v];
    }

private:
    std::vector<bool> marked_;
    std::shared_ptr<Digraph> graph_;

    void dfs(int v) {
        marked_[v] = true;
        for (const auto& w : graph_->adj(v))
            if (!marked_[w])
                dfs(w);
    }
};

}

#endif //LEETCODE_DIRECTEDDFS_HPP
