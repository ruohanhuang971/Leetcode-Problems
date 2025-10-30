#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    - Given a reference of a node in a connected undirected graph.
    - Return a deep copy (clone) of the graph..

    Time: O(V + E), Space: O(V)
*/

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

Node* cloneGraph(Node* node) {
    if (!node)
        return nullptr;

    unordered_map<int, Node*> nodes;
    unordered_set<int> visited;

    Node* head = new Node(node->val);
    nodes[head->val] = head;

    queue<Node*> to_visit;
    to_visit.push(node);
    while (!to_visit.empty()) {
        Node* cur = to_visit.front();
        to_visit.pop();

        if (visited.count(cur->val) == 1) {
            continue;
        }

        visited.insert(cur->val);

        Node* copy;
        auto itr = nodes.find(cur->val);
        if (itr != nodes.end()) {
            copy = itr->second;
        } else {
            copy = new Node(cur->val);
        }

        for (auto i : cur->neighbors) {
            // add neighbors
            auto itr = nodes.find(i->val);
            if (itr != nodes.end()) {
                copy->neighbors.push_back(itr->second);
            } else {
                Node* neighbor = new Node(i->val);
                copy->neighbors.push_back(neighbor);
                nodes[i->val] = neighbor;

                to_visit.push(i);
            }
        }
    }
    return head;
}