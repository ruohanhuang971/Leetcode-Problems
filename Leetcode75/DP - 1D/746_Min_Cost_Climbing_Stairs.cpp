#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
    Approach:
        - create dp array, dp[i] represents the minimum cost to reach the ith step
        - dp[0] = 0 and dp[1] = 0 because can start from step 0 or step 1
        - iterate through 2 to n, computing dp[i] as the minimum of the two previous steps
        - return dp[n] => minimum cost to reach the top
*/

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
}