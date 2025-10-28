#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    I use the BFS approach
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
    if (!node) return nullptr;

    Node* head = new Node(node->val);
    if (node->neighbors.empty()) return head;

    unordered_set<int> visited;
    queue<Node*> to_visit;
    to_visit.push(node);
    map<int, Node*> graph;
    graph[node->val] = head;
    while (!to_visit.empty()) {
        Node* next = to_visit.front();
        to_visit.pop();

        if (visited.count(next->val) == 1) {
            continue;
        }
        // set visited
        visited.insert(next->val);

        Node* new_Node;
        // if node doesn't exist yet -> make new nodes
        if (graph.count(next->val) == 0) {
            new_Node = new Node(next->val);
        } else {
            // update the stuff for the already existed node
            new_Node = graph[next->val];
        }

        for (auto n : next->neighbors) {
            // if neighbor don't exist yet -> make empty node
            // if neighbor exist -> reference
            Node* neighbor;
            if (graph.count(n->val) == 0) {
                neighbor = new Node(n->val);
                new_Node->neighbors.push_back(neighbor);
                graph[n->val] = neighbor;
            } else {
                neighbor = graph[n->val];
                new_Node->neighbors.push_back(neighbor);
            }
            to_visit.push(n);
        }

        // add new nodes to graph
        graph[new_Node->val] = new_Node;
    }

    return head;
}

/*
    DSF approach
*/
Node* cloneGraph(Node* node) {
    if (!node) return nullptr;

    // map original nodes to clones
    unordered_map<Node*, Node*> visited;

    return dfs(node, visited);
}

Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
    if (visited.count(node)) {
        return visited[node];
    }

    Node* clone = new Node(node->val);

    // IMPORTANT: Add the mapping BEFORE processing neighbors prevents cycles
    visited[node] = clone;

    // Process all neighbors of the current node
    for (Node* neighbor : node->neighbors) {
        // Recursively clone each neighbor and add to current clone's neighbor list
        // The recursive call will either:
        // 1. Create a new clone if neighbor hasn't been visited
        // 2. Return existing clone if neighbor was already processed
        clone->neighbors.push_back(dfs(neighbor, visited));
    }

    return clone;
}