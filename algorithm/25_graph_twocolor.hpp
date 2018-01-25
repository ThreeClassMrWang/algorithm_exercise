//
// Created by wcj on 1/25/18.
//

#ifndef LEETCODE_25_GRAPH_TWOCOLOR_HPP
#define LEETCODE_25_GRAPH_TWOCOLOR_HPP

/// 图搜索的双色问题

#include <vector>
#include "GraphUtil.hpp"

namespace algorithm {

class TwoColor {
public:
    explicit TwoColor(const std::shared_ptr<Graph>& graph) :
            marked_(graph->V(), false), color_(graph->V(), Color::RED), isTwoColorable_(true), graph_(graph) {
        for (int s{0}; s < graph_->V(); ++s)
            if (!marked_[s])
                dfs(s);
    }

    bool isTwoColorable() const noexcept { return isTwoColorable_; }

private:
    enum class Color : char {
        RED = 0,
        BLACK,
    };

    std::vector<bool> marked_;
    std::vector<Color> color_;
    bool isTwoColorable_;
    std::shared_ptr<Graph> graph_;

    void dfs(int v) {
        marked_[v] = true;
        for (const auto& w : graph_->adj(v)) {
            if (!marked_[w]) {
                color_[w] = (color_[v] == Color::RED ? Color::BLACK : Color::RED);
                dfs(w);
            } else if (color_[w] == color_[v])
                isTwoColorable_ = false;
        }
    }
};

}

#endif //LEETCODE_25_GRAPH_TWOCOLOR_HPP
