/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function (board, word) {
    const n = board.length;
    const m = board[0].length;
    const visited = Array.from({ length: n }, () => Array(m).fill(0));

    for (let row = 0; row < n; row++) {
        for (let col = 0; col < m; col++) {
            if (helper(board, row, col, word, 0, visited)) {
                return true;
            }
        }
    }
    return false;
};

function helper(board, row, col, word, index, visited) {
    if (word.length <= index || visited[row][col]) return false;
    if (board[row][col] !== word[index]) return false;
    if (word.length - 1 === index) return true;

    visited[row][col] = true;

    const dir = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    for (const [dr, dc] of dir) {
        const newRow = row + dr;
        const newCol = col + dc;

        // bound checking
        if (newRow < 0 || newRow >= board.length || newCol < 0 || newCol >= board[0].length) {
            continue;
        }
        if (helper(board, newRow, newCol, word, index + 1, visited)) return true;
    }

    visited[row][col] = false;

    return false;
}