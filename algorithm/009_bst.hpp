//
// Created by wcj on 3/1/18.
//

#ifndef LEETCODE_009_BST_HPP
#define LEETCODE_009_BST_HPP

#include <vector>
#include "SortUtil.hpp"

namespace algorithm {

template <typename KEY, typename VALUE, typename COMPARE>
class BST009 {
 public:
  BST009() : root_(nullptr) { }

  std::size_t size() const noexcept { return size(root_); }
  const VALUE* get(const KEY& key) const noexcept { return get(root_, key); }
  void put(const KEY& key, const VALUE& value) { root_ = put(root_, key, value); }
  std::pair<KEY, VALUE> min() const noexcept { };

 private:
  class Node {
   public:
    KEY key_;
    VALUE value_;
    Node* left_;
    Node* right_;
    std::size_t N_;

    Node(const KEY& key, const VALUE& value, std::size_t N = 1) :
        key_(key), value_(value), left_(nullptr), right_(nullptr), N_(N) { }
    Node(KEY&& key, VALUE&& value, std::size_t N = 1) :
        key_(std::move(key)), value_(std::move(value)), left_(nullptr), right_(nullptr), N_(N) { }
  };

  Node* root_;
  COMPARE cmp_;

  std::size_t size(const Node* root) const noexcept {
    if (!root) return 0;
    return root->N_;
  }

  const VALUE* get(const Node* root, const KEY& key) const noexcept {
    if (!root) return nullptr;
    int res = cmp_(key, root->key_);
    if (res > 0) return get(root->right_, key);
    else if (res < 0) return get(root->left_, key);
    else return &root->value_;
  }

  Node* put(Node* root, const KEY& key, const VALUE& value) {
    if (!root) return new Node(key, value);
    int res = cmp_(key, root->key_);
    if (res < 0) root->left_ = put(root->left_, key, value);
    else if (res > 0) root->right_ = put(root->right_, key, value);
    else root->value_ = value;

    root->N_ = size(root->left_) + size(root->right_) + 1;
    return root;
  }

  const Node* min(const Node* root) const noexcept {
    if (root->left_ == nullptr) return root;
    return min(root->left_);
  }

};

}

#endif //LEETCODE_009_BST_HPP
