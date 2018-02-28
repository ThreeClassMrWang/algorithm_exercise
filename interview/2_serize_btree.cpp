//
// Created by wcj on 1/9/18.
//

#include <memory>
#include <iostream>
#include <vector>
#include <sstream>
#include <deque>

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
void serize_btree(std::shared_ptr<Node<T>> head) {
  if (!head) {
    std::cout << "#!";
    return;
  }

  std::cout << head->value_ << "!";
  serize_btree(head->left_);
  serize_btree(head->right_);
}

template<typename T = int>
std::size_t get_btree_height(std::shared_ptr<Node<T>> head, std::size_t len) {
  if (!head) return len;
  return std::max(get_btree_height(head->left_, len + 1), get_btree_height(head->right_, len + 1));
}

template<typename T = int>
std::deque<T> get_int_from_string(std::string s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::deque<T> tokens;
  while (getline(ss, item, delim)) {
    tokens.push_back(std::stoi(item));
  }
  return tokens;
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

  serize_btree(nodeVector[0]);
  std::cout << std::endl;

  std::cout << "Btree Height: " << get_btree_height(nodeVector[0], 0) << std::endl;
}