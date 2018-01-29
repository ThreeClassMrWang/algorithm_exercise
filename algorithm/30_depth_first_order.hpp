//
// Created by wcj on 1/28/18.
//

#ifndef LEETCODE_30_DEPTH_FIRST_ORDER_HPP
#define LEETCODE_30_DEPTH_FIRST_ORDER_HPP

/// 深度优先搜索排序

#include <vector>
#include <queue>
#include <stack>
#include "DigraphUtil.hpp"

namespace algorithm {

class DepthFirstOrder {
public:
    explicit DepthFirstOrder(const std::shared_ptr<Digraph>& graph) :
            marked_(graph->V(), false), graph_(graph) {
        for (int v{0}; v < graph->V(); ++v)
            if (!marked_[v])
                dfs(v);
    }

    const std::queue<int>& pre() const noexcept { return pre_; }
    const std::queue<int>& post() const noexcept { return post_; }
    const std::stack<int>& reversePost() const noexcept { return reversePost_; }

private:
    std::vector<bool> marked_;
    std::queue<int> pre_;
    std::queue<int> post_;
    std::stack<int> reversePost_;
    std::shared_ptr<Digraph> graph_;

    void dfs(int v) {
        pre_.push(v);

        marked_[v] = true;
        for (const auto& w : graph_->adj(v)) {
            if (!marked_[w])
                dfs(w);
        }

        post_.push(v);
        reversePost_.push(v);
    }
};

}

#endif //LEETCODE_30_DEPTH_FIRST_ORDER_HPP
