#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an integer array nums representing the amount of money of each house
        - but now the house is in a circle so House[1] and House[n] are adjacent
    - Return the maximum amount of money you can rob tonight without alerting the police.

    Time: O(N), Space complexity: O(1)
*/

/*
    Since House[1] and House[n] are adjacent, they cannot be robbed together
        => problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money

    - this simplifies the problem to House Robber, which is already been solved.
*/

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    return max(houseRobber(nums, 0, n - 1), houseRobber(nums, 1, n));
}

int houseRobber(vector<int>& nums, int left, int right) {
    int prev = 0;
    int cur = nums[left];

    for (int i = left + 1; i < right; i++) {
        int temp = cur;
        cur = max(nums[i] + prev, cur);
        prev = temp;
    }
    return cur;
}