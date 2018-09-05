//
// Created by wcj on 1/26/18.
//

#ifndef LEETCODE_DIGRAPH_HPP
#define LEETCODE_DIGRAPH_HPP

/// 有向图相关算法

#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <bits/shared_ptr.h>
#include <fstream>

namespace algorithm {

class Digraph {
 public:
  Digraph() : V_(0), E_(0), adj_() {}

  void addEdge(int v, int w) {
    adj_[v].insert(w);
    ++E_;
    V_ = adj_.size();
  }

  std::size_t V() const noexcept { return V_; }
  std::size_t E() const noexcept { return E_; }

  const std::unordered_set<int> &adj(int v) {
    return adj_[v];
  }

  std::shared_ptr<Digraph> reverse() {
    auto ptr = std::make_shared<Digraph>();
    for (const auto &v : adj_)
      for (const auto &w : v.second)
        ptr->addEdge(w, v.first);       // reverse

    return ptr;
  }

  std::string toString() {
    std::string res = std::to_string(V_) + " vetices, " + std::to_string(E_) + " edges\n";
    for (const auto &v : adj_) {
      res += std::to_string(v.first) + ": ";
      for (const auto &w : v.second)
        res += std::to_string(w) + " ";
      res += "\n";
    }

    return res;
  }

 private:
  std::size_t V_;
  std::size_t E_;
  std::map<int, std::unordered_set<int>> adj_;    // 邻接表结构
};

class DigraphFactory {
 public:
  explicit DigraphFactory(const std::string &filename) :
      fileName_(filename), dataStream_(filename) {}

  std::shared_ptr<Digraph> genDigraph() {
    auto ptr = std::make_shared<Digraph>();
    std::size_t V, E;
    dataStream_ >> V >> E;
    int v, w;
    while (!dataStream_.eof()) {
      dataStream_ >> v >> w;
      ptr->addEdge(v, w);
    }

    return ptr;
  }

 private:
  std::string fileName_;
  std::ifstream dataStream_;
};

}

#endif //LEETCODE_DIGRAPH_HPP
