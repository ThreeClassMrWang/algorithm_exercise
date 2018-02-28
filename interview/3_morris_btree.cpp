//
// Created by wcj on 1/9/18.
//

#include <iostream>
#include <memory>
#include <vector>

class Node {
 public:
  int value_;
  std::shared_ptr<Node> left_;
  std::shared_ptr<Node> right_;

  Node(int value) : value_(value), left_(nullptr), right_(nullptr) {}
};

void morrisInOrderLoop(std::shared_ptr<Node> head) {
  if (!head) return;

  auto cur1 = head;
  decltype(head) cur2 = nullptr;

  while (cur1 != nullptr) {
    cur2 = cur1->left_;
    if (cur2 != nullptr) {
      while (cur2->right_ != nullptr && cur2->right_ != cur1)
        cur2 = cur2->right_;

      if (cur2->right_ == nullptr) {
        cur2->right_ = cur1;
        cur1 = cur1->left_;
        continue;
      } else {
        cur2->right_ = nullptr;
      }
    }
    std::cout << cur1->value_ << std::endl;
    cur1 = cur1->right_;
  }
}

void mirrisPreOrderLoop(std::shared_ptr<Node> head) {
  if (!head) return;

  auto cur1 = head;
  decltype(head) cur2 = nullptr;

  while (cur1 != nullptr) {
    cur2 = cur1->left_;
    if (cur2 != nullptr) {
      while (cur2->right_ != nullptr && cur2->right_ != cur1)
        cur2 = cur2->right_;

      if (cur2->right_ == nullptr) {
        std::cout << cur1->value_ << std::endl;
        cur2->right_ = cur1;
        cur1 = cur1->left_;
        continue;
      } else {
        cur2->right_ = nullptr;
      }
    } else {
      std::cout << cur1->value_ << std::endl;
    }

    cur1 = cur1->right_;
  }
}

int main(int, char **) {
  std::vector<std::shared_ptr<Node>> nodeVector;
  constexpr int NUM = 10;
  for (int i = 0; i < NUM; i++)
    nodeVector.emplace_back(std::make_shared<Node>(i));

  nodeVector[0]->left_ = nodeVector[1];
  nodeVector[0]->right_ = nodeVector[2];
  nodeVector[1]->left_ = nodeVector[3];
  nodeVector[1]->right_ = nodeVector[4];
  nodeVector[2]->left_ = nodeVector[5];
  nodeVector[3]->right_ = nodeVector[6];
  nodeVector[5]->left_ = nodeVector[7];
  nodeVector[7]->left_ = nodeVector[8];

  std::cout << "Mirris inorder\n";
  morrisInOrderLoop(nodeVector[0]);
  std::cout << "Mirris preorder\n";
  mirrisPreOrderLoop(nodeVector[0]);
}
