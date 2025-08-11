#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    unordered_map<string, int> mapp;
    int n = grid.size();

    for (int i = 0; i < n; i++) {
        string temp;
        for (int j = 0; j < n; j++) {
            temp += to_string(grid[j][i]) +
                    ',';  // Store each column as a string
        }
        mapp[temp]++;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        string temp;
        for (int j = 0; j < n; j++) {
            temp += to_string(grid[i][j]) + ',';  // Form string for each row
        }
        res += mapp[temp];  // Match row with column
    }

    return res;
}
