//
// Created by wcj on 1/9/18.
//

#include <memory>
#include <iostream>
#include <vector>
#include <unordered_map>

class Node {
 public:
  int value_;
  std::shared_ptr<Node> left_;
  std::shared_ptr<Node> right_;

  Node(int value) : value_(value), left_(nullptr), right_(nullptr) {}
};

void insertMap(int key, const std::pair<int, int> &item, std::unordered_map<int, int> &map) {
  auto it = map.find(key);
  if (it != map.end()) {
    map.erase(it);
  }

  map[item.first] = item.second;
}

void getMaxSumLength(std::shared_ptr<Node> head, std::unordered_map<int, int> &map, const int &sum, int &maxLen) {
  if (!head) return;

  getMaxSumLength(head->left_, map, sum, maxLen);
  getMaxSumLength(head->right_, map, sum, maxLen);

  auto tmpMap = map;
  for (const auto &item : tmpMap) {
    insertMap(item.first, std::make_pair(item.first + head->value_, item.second + 1), map);
  }
  insertMap(head->value_, std::make_pair(head->value_, 1), map);

  auto it = map.find(sum);
  if (it != map.end())
    maxLen = std::max(maxLen, it->second);
}

int getMaxSumLength(std::shared_ptr<Node> head, const int &sum) {
  std::unordered_map<int, int> map;
  int maxLen = 0;
  getMaxSumLength(head, map, sum, maxLen);

  return maxLen;
}

int main(int, char **) {
  std::shared_ptr<Node> root = std::make_shared<Node>(-3);
  decltype(root) node1 = std::make_shared<Node>(3);
  decltype(root) node2 = std::make_shared<Node>(-9);
  root->left_ = node1;
  root->right_ = node2;
  decltype(root) node3 = std::make_shared<Node>(1);
  decltype(root) node4 = std::make_shared<Node>(0);
  node1->left_ = node3;
  node1->right_ = node4;
  decltype(root) node5 = std::make_shared<Node>(1);
  decltype(root) node6 = std::make_shared<Node>(6);
  node4->left_ = node5;
  node4->right_ = node6;
  decltype(root) node7 = std::make_shared<Node>(2);
  decltype(root) node8 = std::make_shared<Node>(1);
  node2->left_ = node7;
  node2->right_ = node8;

  std::cout << "sum 6 :" << getMaxSumLength(root, 6) << std::endl;
  std::cout << "Sum -9 :" << getMaxSumLength(root, -9) << std::endl;
}


