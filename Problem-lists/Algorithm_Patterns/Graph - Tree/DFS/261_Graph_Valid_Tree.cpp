#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    - Graph of n nodes labeled from 0 to n - 1.
    - Given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between
      nodes ai and bi in the graph.
    - Return true if the edges of the given graph make up a valid tree, and false otherwise.

    Time: O(V + E) [dfs check each node once and check every edge of node], Space: O(V + E) [Adjacency list]
*/

/*
    Valid tree:
        - all nodes are connected
        - no cycles
        - if there are n nodes, there are n - 1 edges
*/

bool validTree(int n, vector<vector<int>>& edges) {
    if (n - 1 != edges.size()) return false;
    if (n == 1) return true;

    // construct map
    unordered_map<int, vector<int>> nodes;
    for (auto& edge : edges) {
        nodes[edge[0]].push_back(edge[1]);
        nodes[edge[1]].push_back(edge[0]);
    }

    // check there are no cycles with dfs
    vector<bool> visited(n, false);
    if (!dfs(0, -1, nodes, visited)) {
        return false;
    }

    //  check all nodes are visited
    for (auto v : visited) {
        if (!v) {
            return false;
        }
    }
    return true;
}

// DFS - check for cycles + connection
bool dfs(int node, int parent, unordered_map<int, vector<int>>& nodes, vector<bool>& visited) {
    visited[node] = true;

    for (auto neighbor : nodes[node]) {
        if (neighbor == parent) continue;     // Skip parent
        if (visited[neighbor]) return false;  // cycle
        if (!dfs(neighbor, node, nodes, visited)) return false;
    }
    return true;
}