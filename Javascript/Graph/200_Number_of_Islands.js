/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function (grid) {
    let ans = 0;
    for (let row = 0; row < grid.length; row++) {
        for (let col = 0; col < grid[0].length; col++) {
            if (grid[row][col] == '1') {
                removeIsland(grid, row, col);
                ans++;
            }
        }
    }
    return ans;
};

const dir = [[1, 0], [-1, 0], [0, 1], [0, -1]];
function removeIsland(grid, row, col) {
    // bound checking
    if (row < 0 || row >= grid.length || col < 0 || col >= grid[0].length) return;
    if (grid[row][col] !== '1') return;

    grid[row][col] = '-';
    for ([dr, dc] of dir) {
        removeIsland(grid, row + dr, col + dc);
    }
}