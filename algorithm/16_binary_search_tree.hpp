//
// Created by wcj on 1/20/18.
//

#ifndef LEETCODE_16_BINARY_SEARCH_TREE_HPP
#define LEETCODE_16_BINARY_SEARCH_TREE_HPP

#include <cstddef>
#include <utility>

namespace algorithm {

template <typename Key, typename Value>
class BinarySearchTree {
public:
    BinarySearchTree() = default;
    ~BinarySearchTree() {
        root_ = del(root_);
    }

    // Copy is forbidden
    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree(BinarySearchTree&&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(BinarySearchTree&&) = delete;

    std::size_t size() const noexcept { return size(root_); }
    const Value* get(const Key& key) const noexcept { return get(root_, key); }
    void put(const Key& key, const Value& value) { root_ = put(root_, key, value); }
    const Key* min() const noexcept { Node* m = min(root_); if (m == nullptr) return nullptr; else return &m->key_; }
    const Key* max() const noexcept { Node* m = max(root_); if (m == nullptr) return nullptr; else return &m->key_; }
    const Key* select(std::size_t k) const noexcept {
        Node* target = select(root_, k);
        if (target == nullptr) return nullptr;
        else return &target->key_;
    }
    std::size_t rank(const Key& key) const noexcept { return rank(root_, key); }
    void delMin() { root_ = delMin(root_); }
    void delKey(const Key& key) { root_ = deleteKey(root_, key); }

private:

    struct Node {
        Key key_;
        Value value_;
        Node* left_;
        Node* right_;
        std::size_t N_;

        Node(const Key& k, const Value& v, std::size_t n) :
                key_(k), value_(v), N_(n), left_(nullptr), right_(nullptr) {}
        Node(Key&& k, Value&& v, std::size_t n) :
                key_(std::move(k)), value_(std::move(v)), N_(n), left_(nullptr), right_(nullptr) {}
    };

    Node* root_ {nullptr};

    std::size_t size(Node* root) const noexcept {
        if (root == nullptr) return 0;
        return root->N_;
    }

    const Value* get(Node* root, const Key& key) const noexcept {
        if (root == nullptr) return nullptr;
        if (key == root->key_) return &root->value_;
        else if (key > root->key_) get(root->right_, key);
        else get(root->left_, key);
    }

    Node* put(Node* root, const Key& key, const Value& value) {
        if (root == nullptr) return new Node(key, value, 1);
        if (key < root->key_) root->left_ = put(root->left_, key, value);
        else if(key > root->key_) root->right_ = put(root->right_, key, value);
        else root->value_ = value;
        root->N_ = size(root->left_) + size(root->right_) + 1;
        return root;
    }

    Node* del(Node* root) {
        if (root == nullptr) return nullptr;
        root->left_ = del(root->left_);
        root->right_ = del(root->right_);
        delete root;
        root = nullptr;
        return root;
    }

    Node* min(Node* root) const noexcept {
        if (root == nullptr) return nullptr;
        if (root->left_ == nullptr) return root;
        return min(root->left_);        // CPS
    }

    Node* max(Node* root) const noexcept {
        if (root == nullptr) return nullptr;
        if (root->right_ == nullptr) return root;
        return max(root);
    }

    Node* select(Node* root, std::size_t k) const noexcept {
        if (root == nullptr) return nullptr;
        std::size_t t = size(root->left_);
        if (t == k) return root;
        else if (t > k) select(root->left_, k);
        else select(root->right_, k - t - 1);
    }

    std::size_t rank(Node* root, const Key& key) const noexcept {
        if (root == nullptr) return 0;
        if (key == root->key_) return size(root->left_);
        else if (key > root->key_) return 1 + size(root->left_) + rank(root->right_, key);
        else rank(root->left_, key);
    }

    Node* delMin(Node* root) {
        if (root->left_ == nullptr) {
            Node* right = root->right_;
            delete root;
            return right;
        }

        root->left_ = delMin(root->left_);
        root->N_ = size(root->left_) + size(root_->right_) + 1;
        return root;
    }

    Node* deleteKey(Node* root, const Key& key) {
        if (root == nullptr) return nullptr;
        if (root->key_ > key) root->left_ = deleteKey(root->left_, key);
        else if (root->key_ < key) root->right_ = deleteKey(root->right_, key);
        else {
            if (root->left_ == nullptr) {
                Node* r = root->right_;
                delete root;
                return r;
            }
            if (root->right_ == nullptr) {
                Node* l = root->left_;
                delete root;
                return l;
            }

            Node* r = root->right_;
            Node* l = root->left_;
            delete root;
            root = min(root->right_);
            root->left_ = l;
            root->right_ = delMin(root->right_);
        }

        root->N_ = size(root->left_) + size(root->right_) + 1;
        return root;
    }

};

}

#endif //LEETCODE_16_BINARY_SEARCH_TREE_HPP
