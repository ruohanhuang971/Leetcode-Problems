#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an integer array nums representing the amount of money of each house
    - Return the maximum amount of money you can rob tonight without alerting the police.

    Time: O(N), Space complexity: O(1)
*/

int rob(vector<int>& nums) {
    int prev = 0;
    int next = 0;

    // at each house
    for (auto n : nums) {
        int temp = next;
        // either take from two houses ago and current house or take the previous house
        next = max(temp, prev + n);
        prev = temp;
    }

    return next;
}