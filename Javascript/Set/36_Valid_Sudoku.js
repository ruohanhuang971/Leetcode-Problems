/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
    for (let i = 0; i < 9; i++) {
        const row = new Set();
        const col = new Set();
        const block = new Set();
        for (let j = 0; j < 9; j++) {
            // row
            if (board[i][j] != "." && row.has(board[i][j])) return false;
            else row.add(board[i][j])

            // col
            if (board[j][i] != "." && col.has(board[j][i])) return false;
            else col.add(board[j][i])

            const r = 3 * Math.floor(i / 3) + Math.floor(j / 3);
            const c = 3 * Math.floor(i % 3) + Math.floor(j % 3);
            if (board[r][c] != "." && block.has(board[r][c])) return false;
            else block.add(board[r][c])
        }
    }
    return true;
};