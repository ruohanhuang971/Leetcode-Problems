#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an integer array nums
    - return the length of the longest strictly increasing subsequence.

    Time: O(N^2), Space: O(N)
*/

/*
    Intuition:
    - At each position, consider all valid ways to extend previous subsequences
    - Keep track of the best solution ending at each position
*/

int lengthOfLIS(vector<int>& nums) {
    // for the element keep track of how many previous elements are smaller than it
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // find a previous smaller element that has a longer sequence

            if (nums[i] > nums[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}