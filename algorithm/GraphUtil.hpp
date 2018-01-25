//
// Created by wcj on 1/25/18.
//

#ifndef LEETCODE_GARAPHUTIL_HPP
#define LEETCODE_GARAPHUTIL_HPP

#include <cstddef>
#include <vector>
#include <memory>
#include <unordered_set>
#include <string>
#include <fstream>
#include <unordered_map>

namespace algorithm {

class Graph {
public:
    explicit Graph() : V_(0), E_(0) { }

    std::size_t V() const noexcept { return V_; }
    std::size_t E() const noexcept { return E_; }

    void addEdge(int v, int w) {
        adj_[v].insert(w);
        adj_[w].insert(v);
        ++E_;
        V_ = adj_.size();
    }

    const std::unordered_set<int>& adj(int v) noexcept {
        return adj_[v];
    }

    // Common algorithm about graph
    std::size_t degree(int v) noexcept {
        return adj_[v].size();
    }

    std::size_t maxDegree() const noexcept {
        std::size_t max = 0;
        for (const auto& a : adj_)
            max = std::max(max, a.second.size());
        return max;
    }

    double avgDegree() const noexcept {
        return (2.0 * (E_ / V_));
    }

    std::string toString() {
        std::string s = std::to_string(V_) + " vertices, " + std::to_string(E_) + " edges\n";
        for (std::size_t i{0}; i < V_; ++i) {
            s += std::to_string(i) + ": ";
            for (const auto& e : adj_[i])
                s += std::to_string(e) + " ";
            s += "\n";
        }

        return s;   // RVO or NVO
    }

private:
    std::size_t V_;  // Size of vertices
    std::size_t E_;  // Size of edges
    std::map<int, std::unordered_set<int>> adj_;   // 邻接表
};

class GraphFactory {
public:
    explicit GraphFactory(const std::string& datafile) : dataFile_(datafile), dataStream_(datafile) { }

    std::shared_ptr<Graph> genGraph() {
        std::size_t V, E;
        dataStream_ >> V >> E;
        auto gptr = std::make_shared<Graph>();
        for (std::size_t i{0}; i < E; ++i) {
            int v, w;
            dataStream_ >> v >> w;
            gptr->addEdge(v, w);
        }
        return gptr;
    }

private:
    std::string dataFile_;
    std::ifstream dataStream_;
};

class SymbolGraph {
public:
    SymbolGraph() : graph_(std::make_shared<Graph>()) { }

    void addEdge(const std::string& symV, const std::string& symW) {
        auto it = symbolTable_.find(symV);
        if (it == symbolTable_.end()) {
            int size = (int) symbolTable_.size();
            symbolTable_[symV] = size, keys[size] = symV;
        }
        it = symbolTable_.find(symW);
        if (it == symbolTable_.end()) {
            int size = (int) symbolTable_.size();
            symbolTable_[symW] = size, keys[size] = symW;
        }
        graph_->addEdge(symbolTable_[symV], symbolTable_[symW]);
    }

    bool contains(const std::string& s) {
        auto it = symbolTable_.find(s);
        return (it != symbolTable_.end());
    }

    int index(const std::string& s) {
        if (!contains(s)) return -1;
        return symbolTable_[s];
    }

    const std::string& name(int v) {
        return keys[v];
    }

    const std::shared_ptr<Graph>& G() const noexcept { return graph_; }

    std::string toString() {
        std::string res = std::to_string(graph_->V()) + " vertices, " + std::to_string(graph_->E()) + " edges\n";
        for (int i{0}; i < graph_->V(); ++i) {
            res += name(i) + ": ";
            for (const auto& w : graph_->adj(i))
                res += name(w) + " ";
            res += "\n";
        }

        return res;
    }

private:
    std::unordered_map<std::string, int> symbolTable_;
    std::unordered_map<int, std::string> keys;
    std::shared_ptr<Graph> graph_;
};

class SymbolGraphFactory {
public:
    explicit SymbolGraphFactory(const std::string& filename) :
            fileName_(filename), dataStream_(filename) { }

    std::shared_ptr<SymbolGraph> genSymbolGraph() {
        auto graph = std::make_shared<SymbolGraph>();
        std::string strV, strW;
        while(!dataStream_.eof()) {
            dataStream_ >> strV >> strW;
            graph->addEdge(strV, strW);
        }

        return graph;
    }

private:
    std::string fileName_;
    std::ifstream dataStream_;
};

}

#endif //LEETCODE_GARAPHUTIL_HPP
