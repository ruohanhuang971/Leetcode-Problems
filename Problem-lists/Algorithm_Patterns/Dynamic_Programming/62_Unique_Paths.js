/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function (m, n) {
    let memo = new Array(m).fill(0).map(() => new Array(n));
    return dfs(n, m, 0, 0, memo);
};

function dfs(n, m, row, col, memo) {
    // bound checking
    if (row >= m || col >= n) return 0;
    if (row === m - 1 && col === n - 1) return 1;
    if (memo[row][col] !== undefined) {
        return memo[row][col];
    }

    let res = dfs(n, m, row + 1, col, memo) + dfs(n, m, row, col + 1, memo);
    memo[row][col] = res;
    return res;
}