#include <iostream>
#include <vector>
using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    vector<int> rowMax;
    vector<int> colMax;
    for (int i = 0; i < grid.size(); i++) {
        int culRowMax = 0;
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] > culRowMax) {
                culRowMax = grid[i][j];
            }
        }
        rowMax.push_back(culRowMax);
    }

    for (int i = 0; i < grid.size(); i++) {
        int curColMax = 0;
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[j][i] > curColMax) {
                curColMax = grid[j][i];
            }
        }
        colMax.push_back(curColMax);
    }

    int answer = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            int increased = 0;
            if (rowMax[i] < colMax[j]) {
                increased = rowMax[i];
            } else {
                increased = colMax[j];
            }
            answer += (increased - grid[i][j]);
        }
    }

    return answer;
}
