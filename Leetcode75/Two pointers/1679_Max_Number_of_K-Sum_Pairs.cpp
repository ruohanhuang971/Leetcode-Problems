#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Same logic as the Container of most water:
    have two pointer, move pointers base on calculation

    sort the array so that you know the number only increase when pointer move right and decrease when pointer move left
    Add the number at two pointers, if too big -> move right pointer to the left, if too small -> move left pointer to the right

    Time Complexity: O(n logn) [sort], Space Complexity: O(1)
*/

int maxOperations(vector<int>& nums, int k) {
    int left = 0;
    int right = nums.size() - 1;

    sort(nums.begin(), nums.end());

    int totalOps = 0;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == k) {
            left++;
            right--;
            totalOps++;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    return totalOps;
}