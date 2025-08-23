#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    Time: O (M * N) [size of matrix], Space: O(m × n) [visited matrix]
*/

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    // rewriting with bfs
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    queue<vector<int>> q;  // x, y, steps
    q.push({entrance[0], entrance[1], 0});

    int maxRow = maze.size();
    int maxCol = maze[0].size();
    vector<int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        int row = cur[0];
        int col = cur[1];
        int steps = cur[2];

        if (row < 0 || row >= maxRow || col < 0 || col >= maxCol || maze[row][col] == '+') {  // bound checking & wall checking
            continue;
        }
        if (visited[row][col]) {
            continue;
        }
        visited[row][col] = true;

        if (maze[row][col] == '.' && (row == 0 || row == maxRow - 1 || col == 0 || col == maxCol - 1) && !(row == entrance[0] && col == entrance[1])) {
            return steps;
        }

        // push back up, down, left, right
        vector<int> dir;
        steps++;
        q.push({row + 1, col + 0, steps});
        q.push({row + -1, col + 0, steps});
        q.push({row + 0, col + 1, steps});
        q.push({row + 0, col + -1, steps});
    }

    return -1;
}