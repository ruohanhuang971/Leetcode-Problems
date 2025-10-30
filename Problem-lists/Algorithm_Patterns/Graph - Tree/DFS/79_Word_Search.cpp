#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an m x n grid of characters board and a string word
    - return true if word exists in the grid.

    Time: O(N*M) [each cell visited once], Space: O(N*M) [worse case all cells are '1' and DFS may go as deep as m × n]
*/

/*
    Note:
    - use "int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};" instead of "vector<vector<int> dir = ..." because of overhead
*/

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (board[row][col] == word[0]) {
                if (search(board, word, row, col, 0, m, n)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool search(vector<vector<char>>& board, string word, int row, int col, int k, int m, int n) {
    if (k == word.size()) return true;

    if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word[k]) return false;

    char ch = board[row][col];
    board[row][col] = '\0';

    for (int d = 0; d < 4; ++d) {
        int newRow = row + dir[d][0];
        int newCol = col + dir[d][1];
        if (search(board, word, newRow, newCol, k + 1, m, n))
            return true;
    }

    board[row][col] = ch;

    return false;
}