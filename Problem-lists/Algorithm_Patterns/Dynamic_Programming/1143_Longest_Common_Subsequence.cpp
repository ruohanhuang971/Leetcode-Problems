#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given two strings text1 and text2
    - Return the length of their longest common subsequence. If there is no common subsequence, return 0.

    Time: O(N*M), Space complexity: O(N*M)
*/

/*
    Intuition:
    - if the characters match => extend the longest subsequence from dp[i - 1][j - 1]
    - if characters don't match => either skip i or j and take the max
        - dp[i - 1][j]: that the max of the subsequence that skips text1[i]
*/

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // if the character at text1[i] == text2[j] add to the previous
            // subsequence length from text1[i - 1], text2[j - 1] ig
            if (text1[i] == text2[j]) {
                dp[i + 1][j + 1] = 1 + dp[i][j];
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    return dp[n][m];
}