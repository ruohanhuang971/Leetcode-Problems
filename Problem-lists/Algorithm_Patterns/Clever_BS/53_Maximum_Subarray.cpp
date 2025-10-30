#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an integer array nums
    - Find the subarray with the largest sum, and return its sum.

    Time: O(N), Space: O(1)
*/

/*
    Intuition:
    - Kadane's Algo (Algorithm for maximum subarray problem):
        - Core idea: As you scan left → right, keep a running sum.
        - If the running sum ever goes negative, drop it and start fresh at the next element. Track best sum
        - Why it works: A negative running sum can only hurt future totals—so reset early and often.
*/

int maxSubArray(vector<int>& nums) {
    int curSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        curSum = max(nums[i], curSum + nums[i]);
        maxSum = max(curSum, maxSum);
    }

    return maxSum;
}