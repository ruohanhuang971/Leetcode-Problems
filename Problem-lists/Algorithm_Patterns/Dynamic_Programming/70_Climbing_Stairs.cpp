#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Each time you can either climb 1 or 2 steps, it take n steps to reach the top
    - In how many distinct ways can you climb to the top?

    Time: O(N), Space complexity: O(N)
*/

// tabulation
int climbStairs(int n) {
    if (n == 1) return 1;
    vector<int> dp(n);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
}

// space optimized (since only the previous 2 values are needed)
int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int prev = 1, curr = 1;
    for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
}