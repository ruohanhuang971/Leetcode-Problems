#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(1)
*/

// Step 1. Recursive (top-down):
// two options at each house:
//      take the most profit from 2 houses ago and rob this house
//      skip this house and take the most profit from a house ago
int rob(vector<int>& nums, int i) {
    if (i < 0) {
        return 0;
    }
    return max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
}

int rob(vector<int>& nums) {
    return rob(nums, nums.size() - 1);
}

// Step 2. Recursive + memo (top-down):
// save a list of all the max profit that has been calculated per house
// if the house profit have already been calcuated -> return that instead of calculating again
int rob(vector<int>& nums, vector<int>& memo, int i) {
    if (i < 0) {
        return 0;
    }
    if (memo[i] >= 0) {
        return memo[i];
    }
    int result = max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    memo[i] = result;
    return result;
}

int rob(vector<int>& nums) {
    vector<int> memo(nums.size());
    return rob(nums, memo, nums.size() - 1);
}

// Step 3. Iterative + memo(bottom - up):
int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int n = nums.size();
    vector<int> money(n + 1);

    money[0] = 0;
    money[1] = nums[0];
    for (int i = 1; i < n; i++) {
        money[i + 1] = max(money[i - 1] + nums[i], money[i]);
    }

    return money[n];
}

// Step 5. Iterative + N variables (bottom-up)
// each loop use only memo[i] and memo[i - 1], so hold them in 2 variables instead of keep the whole list
int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
        int tmp = prev1;
        prev1 = max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
}