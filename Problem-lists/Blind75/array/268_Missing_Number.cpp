#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(1)
    Use the sum formula to find the expected sum, then subtract actual sum to find missing number
*/
int missingNumber(vector<int>& nums) {
    // using the sum formula
    // expected sum
    int n = nums.size();
    int sum = n * (n + 1) / 2;

    int add_sum = 0;
    for (auto n : nums) {
        add_sum += n;
    }

    return sum - add_sum;
}

/*
    Time: O(N), Space: O(1)
    Use property of XOR, num XOR num = 0, and 0 XOR num = num
    first get the expected XOR value, then find the actual XOR value and see what doesn't cancel out
*/
int missingNumber(vector<int>& nums) {
    int n = nums.size();  // If array has n elements, missing number is from 0 to n
    int ans = 0;

    // XOR all numbers from 1 to n (expected numbers)
    for (int i = 1; i <= n; i++) {
        ans = ans ^ i;
    }

    // XOR all numbers in the actual array
    for (int i = 0; i < nums.size(); i++) {
        ans = ans ^ nums[i];
    }

    return ans;  // Only the missing number remains
}