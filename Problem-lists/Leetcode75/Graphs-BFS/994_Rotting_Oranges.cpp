#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    Time: O(N * M), Space: O(N * M)
*/

int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>> visited = grid;

    queue<pair<int, int>> toVisit;
    int countFreshOrange = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (visited[i][j] == 2) {  // if is rotten organge
                toVisit.push({i, j});
            }
            if (visited[i][j] == 1) {  // if is fresh orange
                countFreshOrange++;
            }
        }
    }

    if (countFreshOrange == 0) return 0;  // return done if there are no fresh oranges
    if (toVisit.empty()) return -1;       // return impossible if there are no rotten

    int time = -1;
    // we will cover four directions i.e. up, down, left, right
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    while (!toVisit.empty()) {
        int size = toVisit.size();  // this is same as the BFS tree stuff
        for (int i = 0; i < size; i++) {
            auto [x, y] = toVisit.front();
            toVisit.pop();
            for (auto [dx, dy] : dirs) {
                int i = x + dx;
                int j = y + dy;
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && visited[i][j] == 1) {  // bound checking & is fresh orange
                    visited[i][j] = 2;
                    countFreshOrange--;
                    toVisit.push({i, j});  // new rotten orange add to queue
                }
            }
        }
        time++;  // round is finished -> add time
    }
    if (countFreshOrange == 0) {
        return time;
    }
    return -1;
}