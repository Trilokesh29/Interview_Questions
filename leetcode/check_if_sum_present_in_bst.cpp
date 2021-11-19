// Given the root of a Binary Search Tree and a target number k,
// return true if there exist two elements in the BST such that their sum is
// equal to the given target.

#include <iostream>
#include <unordered_set>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// Preorder traversal all nodes and search the complement visited before.
bool findTarget(TreeNode *root, int target, std::unordered_set<int> &visited) {
  if (!root) {
    return false;
  }
  if (visited.find(target - root->val) != visited.end()) {
    return true;
  }
  // we should mark node 'visited' after checking in case it's counted.
  // For example, target = 4, root->val = 2.
  // If we mark 2 as visited, then we will find 4 - 2 = 2 immediately.
  visited.insert(root->val);
  return findTarget(root->left, target, visited) ||
         findTarget(root->right, target, visited);
}

bool findTarget(TreeNode *root, int k) {
  std::unordered_set<int> visited;
  return findTarget(root, k, visited);
}