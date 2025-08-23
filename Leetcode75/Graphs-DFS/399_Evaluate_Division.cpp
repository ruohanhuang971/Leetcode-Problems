#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    vector<double> ans(queries.size());

    // Build adjacency list representation of the graph
    unordered_map<string, vector<pair<string, double>>> graph;

    for (int i = 0; i < equations.size(); i++) {
        string a = equations[i][0];
        string b = equations[i][1];
        double val = values[i];

        // a/b = val, so b/a = 1/val
        graph[a].push_back({b, val});
        graph[b].push_back({a, 1.0 / val});
    }

    // Process each query
    for (int i = 0; i < queries.size(); i++) {
        string start = queries[i][0];
        string end = queries[i][1];

        // Check if both variables exist in our graph
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
            ans[i] = -1.0;
            continue;
        }

        // Use DFS to find path from start to end
        unordered_set<string> visited;  // Reset for each query
        double result = dfs(graph, start, end, visited);
        ans[i] = result;
    }

    return ans;
}

double dfs(unordered_map<string, vector<pair<string, double>>>& graph,
           string current, string target, unordered_set<string>& visited) {
    // Base case: found the target
    if (current == target) {
        return 1.0;
    }

    // Mark current as visited
    visited.insert(current);

    // Try all neighbors
    for (auto& neighbor : graph[current]) {
        string next = neighbor.first;
        double weight = neighbor.second;

        // Skip if already visited (avoid cycles)
        if (visited.find(next) != visited.end()) {
            continue;
        }

        // Recursively search from neighbor
        double result = dfs(graph, next, target, visited);

        // If we found a path, multiply by the edge weight
        if (result != -1.0) {
            visited.erase(current);  // Backtrack
            return result * weight;
        }
    }

    // Remove from visited set (backtrack)
    visited.erase(current);
    return -1.0;  // Path not found
}