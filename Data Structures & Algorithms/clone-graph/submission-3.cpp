/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
  Node* cloneGraph(Node* node) {

    unordered_map<Node*, Node*> oldNew{};

    return dfs(node, oldNew);
  }

  Node* dfs(Node* node, unordered_map<Node*, Node*>& oldNew) {
    if (node == nullptr) {
      return nullptr;
    }

    if (oldNew.contains(node)) {
      return oldNew[node];
    }

    Node* copy = new Node{node->val};
    oldNew[node] = copy;

    for (Node* n : node->neighbors) {
      copy->neighbors.push_back(dfs(n, oldNew));
    }

    return copy;
  }
};
