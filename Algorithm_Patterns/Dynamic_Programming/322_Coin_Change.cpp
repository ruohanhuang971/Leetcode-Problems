#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an integer array of coins and total amount of money
    - Return the fewest # of coins needed to make up that amount. Return -1 if combination does not exist

    Time: O(Amount∗Len(Coins)), Space: O(Amount)
*/

/*
    Intuition:
    - Keep track of the minimal # of coins needed to make up $0 -> $amount
    - At each position, consider:
        - of the coin can be used
        - the # of coins needed, if using this coin, is dp[amount - coinValue] + 1
        - add the minimal amount of coins to the dp array
*/

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -2);  // set -2 as unprocessed
    dp[0] = 0;

    // from $0 -> $amount
    for (int i = 1; i <= amount; i++) {
        // get the least amount of coin that can be used, or -1
        int minCoins = INT_MAX;
        for (auto n : coins) {
            // try using the coin
            int leftOver = i - n;

            // if it doesn't go over
            if (leftOver >= 0 && dp[leftOver] >= 0) {
                // check dp at that amount
                minCoins = min(minCoins, dp[leftOver] + 1);
            }
        }

        // if can't find a combo -> -1
        if (minCoins == INT_MAX) {
            dp[i] = -1;
        } else {
            dp[i] = minCoins;
        }
    }

    return dp[amount];
}