#include <iostream>
#include <memory>

struct Node {
  Node(int aData) : data(aData) {}
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
  int data;
};

void insert(Node &root, int data) {
  auto fill_node = [data](auto &nodeptr) {
    if (nodeptr) {
      insert(*nodeptr, data);
    } else {
      nodeptr = std::make_unique<Node>(data);
    }
  };

  if (data <= root.data) {
    fill_node(root.left);

  } else {
    fill_node(root.right);
  }
}

bool search(const Node &root, int data) {
  auto search_helper = [data](const auto &nodeptr) {
    if (nodeptr)
      return search(*nodeptr, data);
    return false;
  };
  if (root.data == data)
    return true;
  else if (data <= root.data)
    return search_helper(root.left);
  else
    return search_helper(root.right);
}

void search() {}

int main() { return 0; }