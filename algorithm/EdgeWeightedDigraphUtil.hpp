//
// Created by wcj on 1/29/18.
//

#ifndef LEETCODE_EDGEWEIGHTEDDIGRAPHUTIL_HPP
#define LEETCODE_EDGEWEIGHTEDDIGRAPHUTIL_HPP

/// 带权重的有向图

#include <vector>
#include <memory>
#include <unordered_set>
#include <map>
#include <fstream>
#include <string>

namespace algorithm {

class DirectedEdge {
public:
    friend class DirectedEdgeHash;
    friend class DirectedEdgeEqual;
    friend bool operator>(const DirectedEdge& l, const DirectedEdge& r);

    DirectedEdge(int v, int w, double weight) :
            v_(v), w_(w), weight_(weight) { }

    double weight() const noexcept { return weight_; }
    int from() const noexcept { return v_; }
    int to() const noexcept { return w_; }
    std::string toString() const {
        std::string res = std::to_string(v_) + "->" + std::to_string(w_) + " " + std::to_string(weight_);
        return res;
    }

private:
    int v_;
    int w_;
    double weight_;
};

class DirectedEdgeHash {
public:
    std::size_t operator()(const DirectedEdge& edge) const {
        return std::hash<std::string>()(edge.toString());
    }
};

class DirectedEdgeEqual {
public:
    bool operator()(const DirectedEdge& l, const DirectedEdge& r) const {
        return (l.v_ == r.v_ && l.w_ == r.w_ && l.weight_ == r.weight_);
    }
};

inline bool operator>(const DirectedEdge& l, const DirectedEdge& r) {
    return (l.weight_ > r.weight_);
}

class EdgeWeightedDigraph {
public:
    EdgeWeightedDigraph() : V_(0), E_(0), adj_() { }

    std::size_t V() const noexcept { return V_; }
    std::size_t E() const noexcept { return E_; }

    template <typename DirectedEdge_>
    void addEdge(DirectedEdge_&& edge) {
        adj_[edge.from()].insert(std::forward<DirectedEdge_>(edge));
        ++E_;
        V_ = adj_.size();
    }

    const std::unordered_set<DirectedEdge, DirectedEdgeHash, DirectedEdgeEqual>& adj(int v) {
        return adj_[v];
    }

    std::shared_ptr<std::unordered_set<DirectedEdge, DirectedEdgeHash, DirectedEdgeEqual>> edges() {
        auto set = std::make_shared<std::unordered_set<DirectedEdge, DirectedEdgeHash, DirectedEdgeEqual>>();
        for (const auto& v : adj_)
            for (const auto& e : v.second)
                set->insert(e);
        return set;
    }

    std::string toString() const {
        std::string res = std::to_string(V_) + " vertices, " + std::to_string(E_) + " edges\n";
        for (const auto& v : adj_) {
            res += std::to_string(v.first) + ": ";
            for (const auto& e : v.second)
                res += e.toString() + " ";
            res += "\n";
        }

        return res;
    }

private:
    std::size_t V_;
    std::size_t E_;
    std::map<int, std::unordered_set<DirectedEdge, DirectedEdgeHash, DirectedEdgeEqual>> adj_;
};

class EdgeWeightedDigraphFactory {
public:
    explicit EdgeWeightedDigraphFactory(const std::string& filename) :
            fileName_(filename), dataStream_(filename) { }

    std::shared_ptr<EdgeWeightedDigraph> genDigraph() {
        auto graph = std::make_shared<EdgeWeightedDigraph>();
        std::size_t V, E;
        dataStream_ >> V >> E;
        int v, w;
        double weight;
        while (!dataStream_.eof()) {
            dataStream_ >> v >> w >> weight;
            graph->addEdge(DirectedEdge(v, w, weight));
        }

        return graph;
    }

private:
    std::string fileName_;
    std::ifstream dataStream_;
};

}

#endif //LEETCODE_EDGEWEIGHTEDDIGRAPHUTIL_HPP
