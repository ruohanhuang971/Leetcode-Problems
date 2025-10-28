#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water)
    - return the number of islands.

    Time: O(N*M) [each cell visited once], Space: O(N*M) [worse case all cells are '1' and DFS may go as deep as m × n]
*/

/*
    Intuition:
    - exploring each cell in the grid, when there is a '1' => start new island
    - export all connected land with dfs and mark as explored
*/

int numIslands(vector<vector<char>>& grid) {
    int numIslands = 0;

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            if (grid[row][col] == '1') {
                dfs(row, col, grid);
                numIslands++;
            }
        }
    }
    return numIslands;
}

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int row, int col, vector<vector<char>>& grid) {
    for (auto i : dir) {
        int newRow = row + i[0];
        int newCol = col + i[1];

        // bound checking
        if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()) {
            // is land -> keep exporting connected
            if (grid[newRow][newCol] == '1') {
                // mark as visited
                grid[newRow][newCol] = '-';
                dfs(newRow, newCol, grid);
            }
        }
    }
}