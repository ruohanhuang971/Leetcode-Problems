#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    - Given an unsorted array of integers nums
    - Return the length of the longest consecutive elements sequence.
    Time: O(M * N), Space: O(M + N) [replaceRow at most M entries, replaceCol at most N entries]
*/

void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int> replaceRow;
    unordered_set<int> replaceCol;

    int NUM_ROW = matrix.size();
    int NUM_COL = matrix[0].size();

    for (int row = 0; row < NUM_ROW; row++) {
        for (int col = 0; col < NUM_COL; col++) {
            if (matrix[row][col] == 0) {
                replaceRow.insert(row);
                replaceCol.insert(col);
            }
        }
    }

    for (int row = 0; row < NUM_ROW; row++) {
        for (int col = 0; col < NUM_COL; col++) {
            if (replaceRow.count(row) != 0 || replaceCol.count(col) != 0) {
                matrix[row][col] = 0;
            }
        }
    }
}
