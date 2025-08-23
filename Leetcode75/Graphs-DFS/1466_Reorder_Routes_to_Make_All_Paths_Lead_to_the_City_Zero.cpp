#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
*/

int minReorder(int n, vector<vector<int>>& connections) {
    // make unordered connection
    vector<vector<int>> unordered(n);
    for (int i = 0; i < connections.size(); i++) {
        int start = connections[i][0];
        int end = connections[i][1];

        unordered[start].push_back(-end);
        unordered[end].push_back(start);
    }

    vector<bool> visited(n);
    int ans = 0;
    reorderHelper(unordered, visited, 0, ans);

    return ans;
}

void reorderHelper(vector<vector<int>>& unordered, vector<bool>& visited, int node, int& ans) {
    int curNode = abs(node);
    if (visited[curNode])
        return;

    if (node < 0) {
        ans++;
    }

    visited[curNode] = true;
    for (int i = 0; i < unordered[curNode].size(); i++) {
        int nextNode = unordered[curNode][i];

        reorderHelper(unordered, visited, nextNode, ans);
    }

    return;
}