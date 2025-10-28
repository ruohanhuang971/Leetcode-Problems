#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an array containing n distinct numbers in the range [0, n]
    - return the only number in the range that is missing from the array.

    Time: O(N), Space: O(1)
*/

/*
    Intuition:
    - the missing number is the difference between adding numbers 0 - n and adding up numbers in the array
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