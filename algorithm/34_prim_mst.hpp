//
// Created by wcj on 1/30/18.
//

#ifndef LEETCODE_34_PRIM_MST_HPP
#define LEETCODE_34_PRIM_MST_HPP

/// 非延迟版本的prim实现
/// 基本思想是 切分原理的贪心（？）

#include <vector>
#include <queue>
#include <memory>
#include "EdgeWeightedGraphUtil.hpp"
#include "35_minPQ.hpp"

namespace algorithm {

class PrimMST {
public:
    explicit PrimMST(const std::shared_ptr<EdgeWeightedGraph>& graph) :
            edgeTo_(graph->V(), nullptr), distTo_(graph->V(), std::numeric_limits<double>::max()),
            marked_(graph->V(), false), indexMinPQ_(), graph_(graph) {
        distTo_[0] = 0.0;
        indexMinPQ_.change_insert(Entry(0, distTo_[0]));
        while (!indexMinPQ_.empty())
            visit(indexMinPQ_.pop().first);
    }

    const std::vector<std::shared_ptr<Edge>>& edges() const noexcept {
        return edgeTo_;
    }

    double weight() const noexcept {
        double res = 0.0;
        for (const auto& e : edgeTo_)
            res += e->weight();
        return res;
    }

private:
    std::vector<std::shared_ptr<Edge>> edgeTo_;
    std::vector<double> distTo_;
    std::vector<bool> marked_;

    using Entry = std::pair<int, double>;
    struct Entry_Greater {
    public:
        bool operator()(const Entry& l, const Entry& r) const {
            return (l.second > r.second);
        }
    };
    MinPQ<Entry, Entry_Greater> indexMinPQ_;

    std::shared_ptr<EdgeWeightedGraph> graph_;

    void visit(int v) {
        marked_[v] = true;
        for (const auto& e : graph_->adj(v)) {
            int w = e.other(v);
            if (marked_[w]) continue;
            if (distTo_[w] > e.weight()) {
                edgeTo_[w] = std::make_shared<Edge>(e);
                distTo_[w] = e.weight();
                indexMinPQ_.change_insert(Entry(w, distTo_[w]));
            }
        }
    }

};

}

#endif //LEETCODE_34_PRIM_MST_HPP
