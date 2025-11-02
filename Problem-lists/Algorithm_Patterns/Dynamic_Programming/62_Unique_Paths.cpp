#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given the two integers m and n
    - Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

    Time: O(N*M), Space complexity: O(N*M)
*/

int uniquePaths(int m, int n) {
    vector<vector<int>> memo(m, vector<int>(n, -1));
    return helper(m, n, 0, 0, memo);
}

int helper(int m, int n, int row, int col, vector<vector<int>>& memo) {
    if (row >= m || col >= n) return 0;
    if (row == m - 1 && col == n - 1) return 1;

    if (memo[row][col] != -1) return memo[row][col];

    int ret = helper(m, n, row + 1, col, memo) + helper(m, n, row, col + 1, memo);
    memo[row][col] = ret;
    return ret;
}