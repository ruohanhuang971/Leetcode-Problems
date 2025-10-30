#include <iostream>
#include <vector>
using namespace std;

/*
    - Given the array nums after the possible rotation and an integer target
    - return the index of target if it is in nums, or -1 if it is not in nums.

    Time: O(logN), Space: O(1)
*/

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        // cout << left << " " << mid << " " << right << endl;

        if (nums[mid] > target) {
            // left -target- mid right
            if (nums[left] <= target || (nums[right] > nums[mid])) {
                right = mid - 1;
            } else {
                // left mid -target- right
                left = mid + 1;
            }
        } else {  // mid < target
            // left mid -target- right
            if (nums[right] >= target || (nums[left] < nums[mid])) {
                left = mid + 1;
            } else {
                // left -target- mid right
                right = mid - 1;
            }
        }
    }

    return -1;
}