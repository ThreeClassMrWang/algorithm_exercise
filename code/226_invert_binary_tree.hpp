//
// Created by wcj on 1/9/18.
//

#ifndef LEETCODE_226_INVERT_BINARY_TREE_HPP
#define LEETCODE_226_INVERT_BINARY_TREE_HPP

//Invert a binary tree.
//           4
//         /   \
//        2     7
//      / \   / \
//     1   3 6   9
//to
//         4
//      /   \
//     7     2
//   / \   / \
//  9   6 3   1

// Definition for a binary tree node.

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class InvertBinaryTree {
 public:
  static TreeNode *invertBinaryTree(TreeNode *root) {
    if (!root) return nullptr;

    TreeNode *left = root->left;
    TreeNode *right = root->right;
    root->left = invertBinaryTree(right);
    root->right = invertBinaryTree(left);

    return root;
  }
};

#endif //LEETCODE_226_INVERT_BINARY_TREE_HPP
