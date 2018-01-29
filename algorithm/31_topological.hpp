//
// Created by wcj on 1/28/18.
//

#ifndef LEETCODE_31_TOPOLOGICAL_HPP
#define LEETCODE_31_TOPOLOGICAL_HPP

/// 拓扑排序
/// 无环情况下才存在拓扑排序

#include "29_directed_cycle.hpp"
#include "30_depth_first_order.hpp"

namespace algorithm {

class Topological {
public:
    explicit Topological(const std::shared_ptr<Digraph>& graph) :
            directedCycle_(graph), depthFirstOrder_(graph), cycle_(directedCycle_.hasCycle()) {}

    bool isCycle() const noexcept { return cycle_; }

    const std::stack<int>& preOrder() {
        if (!cycle_) return reversePost_;

        if (reversePost_.empty())
            reversePost_ = depthFirstOrder_.reversePost();
        return reversePost_;
    }

private:
    DirectedCycle directedCycle_;
    DepthFirstOrder depthFirstOrder_;
    bool cycle_;
    std::stack<int> reversePost_;
};

}

#endif //LEETCODE_31_TOPOLOGICAL_HPP
