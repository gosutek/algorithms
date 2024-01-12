#include <climits>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <sys/types.h>
#include <vector>

auto desync_untie = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

struct Node {
  uint64_t d, p, s, min_cost;
  Node *parent;
  std::vector<std::unique_ptr<Node>> children;
  // Partial constructor.
  Node() {
    parent = nullptr;
    d = p = s = min_cost = 0;
  }
  // Normal constructor.
  Node(const uint64_t &dst, Node *parent_)
      : d(dst), parent(parent_) {
    parent->children.push_back(std::move(std::unique_ptr<Node>(this)));
  }
  // This is not needed.
  // Just ->
  void update(const uint64_t &prep, const uint64_t &spd) {
    this->p = prep;
    this->s = spd;
  }
  std::vector<Node *> path_to_root() {
    std::vector<Node *> path;
    Node *n = this;
    while (n->parent) {
      path.push_back(n->parent);
      n = n->parent;
    }
    return path;
  }
};

void relay(const std::vector<Node *> &arr) {
  for (size_t i = 1; i < arr.size(); i++) {
    long int loopMin = LONG_MAX;
    uint64_t cost;
    auto path = arr[i]->path_to_root();
    for (size_t j = 0; j < path.size(); j++) {
      long int inter = path[j]->min_cost - path[j]->d * arr[i]->s;
      loopMin = std::min(loopMin, inter);
    }
    cost = arr[i]->p + arr[i]->s * arr[i]->d + loopMin;
    arr[i]->min_cost = cost;
    std::cout << cost << std::endl;
  }
  return;
}

int main(int argc, char *argv[]) {

  unsigned int N, dst, first, second, prep, spd;
  std::string input_path = "./test_cases/input";
  std::string output_path = "./test_cases/output";
  std::string ext = ".txt";
  std::ifstream input_file, output_file;

  const std::unique_ptr<Node> root = std::make_unique<Node>();
  std::vector<Node *> nodes;

  unsigned int num = 1;
    input_file.open(input_path + std::to_string(num) + ext);
    if (input_file.good()) {
      input_file >> N;
      nodes.reserve(N);
      nodes.resize(N);
      nodes[0] = root.get();
      for (int i = 0; i < N - 1; i++) {
        input_file >> first;
        input_file >> second;
        input_file >> dst;
        unsigned int parent, child;
        if(first < second) {
          parent = first - 1;
          child = second - 1;
        } else {
          parent = second - 1;
          child = first - 1;
        }
        if (!nodes[parent]) { // If parent doesn't exist first create a parentless parent.
          nodes[parent] = new Node();
        }
        if (!nodes[child]) { // If the child doesnt exist create one.
          nodes[child] = new Node(dst,nodes[parent]);
        } else { // If it does then link the parent.
          nodes[child]->parent = nodes[parent];
          nodes[child]->d = dst;
          nodes[parent]->children.push_back(std::move(std::unique_ptr<Node>(nodes[child])));
        }
      }
      for (int i = 1; i < N; i++) {
        input_file >> prep;
        input_file >> spd;
          nodes[i]->update(prep, spd);
      }
    }
    for(size_t i = 1; i < nodes.size(); i++) {
      for(const auto& child : nodes[i]->children) {
        child->d += nodes[i]->d;
      }
    }
    input_file.close();
    relay(nodes);
  return 0;
}
