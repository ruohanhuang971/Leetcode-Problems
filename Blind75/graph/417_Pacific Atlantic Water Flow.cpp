#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

    // dfs for top & left cells
    for (int i = 0; i < m; i++) {
        dfs(heights, 0, i, pacific);
    }
    for (int i = 0; i < n; i++) {
        dfs(heights, i, 0, pacific);
    }

    // dfs for bottom & right cells
    for (int i = 0; i < m; i++) {
        dfs(heights, n - 1, i, atlantic);
    }
    for (int i = 0; i < n; i++) {
        dfs(heights, i, m - 1, atlantic);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}

void dfs(vector<vector<int>>& heights, int row, int col,
         vector<vector<bool>>& visited) {
    visited[row][col] = true;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // visit each direction
    for (auto& d : directions) {
        int newRow = row + d[0];
        int newCol = col + d[1];

        // bound checking
        if (newRow < 0 || newRow >= heights.size() || newCol < 0 || newCol >= heights[0].size()) {
            continue;
        }

        // check visited
        if (visited[newRow][newCol]) continue;

        // check height
        if (heights[newRow][newCol] < heights[row][col]) continue;

        dfs(heights, newRow, newCol, visited);
    }
}