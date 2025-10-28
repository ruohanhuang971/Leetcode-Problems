#include <iostream>
#include <vector>
using namespace std;

/*
    - There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean.
        - Pacific Ocean touches island's left and top edges, Atlantic Ocean touches island's right and bottom edges
    - Given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
        -  rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is
           less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

    - Return a 2D list of grid coordinates rain water can flow from cell to both the Pacific and Atlantic oceans.

    Time: O(N * M) [each cell is visited once], Space: O(N * M) [visited matrix]
*/

/*
    Valid tree:
        - all nodes are connected
        - no cycles
        - if there are n nodes, there are n - 1 edges
*/

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<bool>> reachPacific(heights.size(), vector<bool>(heights[0].size()));
    vector<vector<bool>> reachAtlantic(heights.size(), vector<bool>(heights[0].size()));
    for (int i = 0; i < heights.size(); i++) {
        dfs(i, 0, heights, reachPacific);
        dfs(i, heights[0].size() - 1, heights, reachAtlantic);
    }
    for (int i = 0; i < heights[0].size(); i++) {
        dfs(0, i, heights, reachPacific);
        dfs(heights.size() - 1, i, heights, reachAtlantic);
    }

    vector<vector<int>> ans;
    // check for land that reaches both
    for (int i = 0; i < heights.size(); i++) {
        for (int j = 0; j < heights[0].size(); j++) {
            if (reachPacific[i][j] && reachAtlantic[i][j]) {
                ans.push_back({i, j});
            }
        }
    }

    return ans;
}

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
    if (visited[row][col]) return;

    visited[row][col] = true;

    for (auto n : dir) {
        int newRow = row + n[0];
        int newCol = col + n[1];

        // bound checking
        if (newRow >= 0 && newRow < heights.size() && newCol >= 0 && newCol < heights[0].size()) {
            //  check height
            if (heights[row][col] <= heights[newRow][newCol]) {
                dfs(newRow, newCol, heights, visited);
            }
        }
    }
}