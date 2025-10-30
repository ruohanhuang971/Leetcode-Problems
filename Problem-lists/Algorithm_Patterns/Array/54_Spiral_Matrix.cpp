#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an m x n matrix,
    - Return all elements of the matrix in spiral order.

    Time: O(N*M), Space: O(1)
*/

/*
    Intuition:
    - peel the matrix layer by layer
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // 1. Traverse left → right
        for (int j = left; j <= right; ++j)
            ans.push_back(matrix[top][j]);
        top++;

        // 2. Traverse top → bottom
        for (int i = top; i <= bottom; ++i)
            ans.push_back(matrix[i][right]);
        right--;

        // 3. Traverse right → left (if still valid)
        if (top <= bottom) {
            for (int j = right; j >= left; --j)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }

        // 4. Traverse bottom → top (if still valid)
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }

    return ans;
}