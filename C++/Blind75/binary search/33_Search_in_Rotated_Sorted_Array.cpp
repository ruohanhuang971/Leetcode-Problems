#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(log N) [binary search], Space: O(1)
    Intuition:
    - find out which part of the array is the sorted part
*/

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;  // Found target
        }

        // Check which half is sorted
        if (nums[left] <= nums[mid]) {
            // Left half is sorted
            if (target >= nums[left] && target < nums[mid]) {
                // Target is in sorted left half
                right = mid - 1;
            } else {
                // Target is in right half (possibly rotated)
                left = mid + 1;
            }
        } else {
            // Right half is sorted (left half contains rotation point)
            if (target > nums[mid] && target <= nums[right]) {
                // Target is in sorted right half
                left = mid + 1;
            } else {
                // Target is in left half (contains rotation point)
                right = mid - 1;
            }
        }
    }

    return -1;  // Target not found
}