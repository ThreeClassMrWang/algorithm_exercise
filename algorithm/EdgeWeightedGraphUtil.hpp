//
// Created by wcj on 1/29/18.
//

#ifndef LEETCODE_EDGEWEIGHTEDGRAPH_HPP
#define LEETCODE_EDGEWEIGHTEDGRAPH_HPP

/// 带边权重的无向图

#include <exception>
#include <stdexcept>
#include <map>
#include <unordered_set>
#include <memory>
#include <fstream>

namespace algorithm {

class Edge {
public:
    friend struct EdgeHash;
    friend struct EdgeEqual;
    friend bool operator>(const Edge& l, const Edge& r);

    Edge(int v, int w, double weight) :
            v_(v), w_(w), weight_(weight) {}

    Edge(const Edge &) = default;

    Edge &operator=(const Edge &) = default;

    double weight() const noexcept { return weight_; }

    int either() const noexcept { return v_; }

    int other(int vertex) const {
        if (vertex == v_) return w_;
        else if (vertex == w_) return v_;
        else throw std::runtime_error("Inconsistent edge");
    }

    int compareTo(const Edge &that) const noexcept {
        if (weight() < that.weight()) return -1;
        else if (weight() > that.weight()) return 1;
        else return 0;
    }

    std::string toString() const {
        std::string res = std::to_string(v_) + "-" + std::to_string(w_) + " " + std::to_string(weight_);
        return res;
    }

private:
    int v_;
    int w_;
    double weight_;
};

inline bool operator>(const Edge& l, const Edge& r) {
    return (l.weight_ > r.weight_);
}

struct EdgeHash {
public:
    std::size_t operator()(const Edge& edge) const {
        return std::hash<std::string>()(edge.toString());
    }
};

struct EdgeEqual {
public:
    bool operator()(const Edge& l, const Edge& r) const {
        return l.v_ == r.v_ && l.w_ == r.w_ && l.weight_ == r.weight_;
    }
};

class EdgeWeightedGraph {
public:
    EdgeWeightedGraph() : V_(0), E_(0), adj_() {}

    std::size_t V() const noexcept { return V_; }

    std::size_t E() const noexcept { return E_; }

    void addEdge(const Edge &edge) {
        int v = edge.either();
        int w = edge.other(v);
        adj_[v].insert(edge);
        adj_[w].insert(edge);
        ++E_;
        V_ = adj_.size();
    }

    const std::unordered_set<Edge, EdgeHash, EdgeEqual>& adj(int v) noexcept {
        return adj_[v];
    }

    const std::shared_ptr<std::unordered_set<Edge, EdgeHash, EdgeEqual>> edges() {
        auto set = std::make_shared<std::unordered_set<Edge, EdgeHash, EdgeEqual>>();
        for (const auto &v : adj_)
            for (const auto &e : v.second)
                set->insert(e);
        return set;
    }

    std::string toString() const {
        std::string res = std::to_string(V_) + " vertices, " + std::to_string(E_) + " edges\n";

        for (const auto &v : adj_) {
            res += std::to_string(v.first) + ": ";
            for (const auto &w : v.second)
                res += w.toString() + " ";
            res += "\n";
        }

        return res;
    }

private:
    std::size_t V_;
    std::size_t E_;
    std::map<int, std::unordered_set<Edge, EdgeHash, EdgeEqual>> adj_;
};

class EdgeWeightedGraphFactory {
public:
    explicit EdgeWeightedGraphFactory(const std::string &filename) :
            fileName_(filename), dataStream_(filename) {}

    std::shared_ptr<EdgeWeightedGraph> genEdgeWeightedGraph() {
        auto graph = std::make_shared<EdgeWeightedGraph>();

        std::size_t V, E;
        dataStream_ >> V >> E;
        int v, w;
        double weight;
        while (!dataStream_.eof()) {
            dataStream_ >> v >> w >> weight;
            Edge edge(v, w, weight);
            graph->addEdge(edge);
        }

        return graph;
    }

private:
    std::string fileName_;
    std::ifstream dataStream_;
};

}

#endif //LEETCODE_EDGEWEIGHTEDGRAPH_HPP
