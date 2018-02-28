//
// Created by wcj on 1/9/18.
//

#include <memory>
#include <stack>
#include <iostream>
#include <vector>

template<typename T>
class Node {
 public:
  template<typename Arg>
  Node(Arg &&value) {
    value_ = value;
  }

  T value_;
  std::shared_ptr<Node<T>> left_;
  std::shared_ptr<Node<T>> right_;
};

template<typename T>
void preOrderRecur(std::shared_ptr<Node<T>> node) {
  if (!node) return;

  std::cout << node->value_ << "\n";
  preOrderRecur(node->left_);
  preOrderRecur(node->right_);
}

template<typename T>
void inOrderRecur(std::shared_ptr<Node<T>> node) {
  if (!node) return;

  inOrderRecur(node->left_);
  std::cout << node->value_ << "\n";
  inOrderRecur(node->right_);
}

template<typename T>
void posOrderRecur(std::shared_ptr<Node<T>> node) {
  if (!node) return;

  posOrderRecur(node->left_);
  posOrderRecur(node->right_);
  std::cout << node->value_ << "\n";
}

template<typename T>
void preOrderLoop(std::shared_ptr<Node<T>> node) {
  if (!node) return;

  std::stack<decltype(node)> stk;

  stk.push(node);

  while (!stk.empty()) {
    auto head = stk.top();
    std::cout << head->value_ << std::endl;
    stk.pop();
    if (head->left_)
      stk.push(head->left_);
    if (head->right_)
      stk.push(head->right_);
  }

}

template<typename T>
void inOrderLoop(std::shared_ptr<Node<T>> node) {
  if (!node) return;

  std::stack<decltype(node)> stk;

  while (!stk.empty() || node) {
    if (node) {
      stk.push(node);
      node = node->left_;
    } else {
      node = stk.top();
      std::cout << node->value_ << std::endl;
      stk.pop();
      node = node->right_;
    }
  }
}

template<typename T>
std::size_t getHeight(std::shared_ptr<Node<T>> node, std::size_t len) {
  if (!node) return len;
  return std::max(getHeight(node->left_, len + 1), getHeight(node->right_, len + 1));
}

template<typename T>
void reverseBTree(std::shared_ptr<Node<T>> &node) {
  if (!node) return;
  std::swap(node->left_, node->right_);
  reverseBTree(node->left_);
  reverseBTree(node->right_);
}

template<typename T>
void posOrderLoop(std::shared_ptr<Node<T>> node) {
  if (!node) return;

  std::stack<decltype(node)> stk;
  decltype(node) c = nullptr;
  stk.push(node);
  while (!stk.empty()) {
    c = stk.top();
    if (c->left_ && node != c->left_ && node != c->right_) {
      stk.push(c->left_);
    } else if (c->right_ && node != c->right_) {
      stk.push(c->right_);
    } else {
      std::cout << c->value_ << std::endl;
      stk.pop();
      node = c;
    }
  }

}

int main(int, char **) {
  std::vector<std::shared_ptr<Node<int>>> nodeVector;
  constexpr int NUM = 10;
  for (int i = 0; i < NUM; i++)
    nodeVector.emplace_back(std::make_shared<Node<int>>(i));

  nodeVector[0]->left_ = nodeVector[1];
  nodeVector[0]->right_ = nodeVector[2];
  nodeVector[1]->left_ = nodeVector[3];
  nodeVector[1]->right_ = nodeVector[4];
  nodeVector[2]->left_ = nodeVector[5];
  nodeVector[3]->right_ = nodeVector[6];
  nodeVector[5]->left_ = nodeVector[7];
  nodeVector[7]->left_ = nodeVector[8];

  std::cout << "preOrderRecur:\n";
  preOrderRecur(nodeVector[0]);
  std::cout << "\ninOrderRecur:\n";
  inOrderRecur(nodeVector[0]);
  std::cout << "\nposOrderRecur:\n";
  posOrderRecur(nodeVector[0]);

  std::cout << "\npreOrderLoop:\n";
  preOrderRecur(nodeVector[0]);
  std::cout << "\ninOrderLoop:\n";
  inOrderLoop(nodeVector[0]);
  std::cout << "\nposOrderLoop:\n";
  posOrderLoop(nodeVector[0]);
}
