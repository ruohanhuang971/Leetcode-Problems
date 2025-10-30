#include <iostream>
#include <vector>
using namespace std;

/*
    - Given the sorted rotated array nums of unique elements
    - return the minimum element of this array.

    Time: O(logN), Space: O(1)
*/

/*
    Intuition:
    - there is a point of inflection when the index goes up but the number becomes smaller
*/

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    if (nums.size() == 1) return nums[0];

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // cout << left << " " << mid << " " << right << endl;

        if (mid > 0 && nums[mid] < nums[mid - 1]) return nums[mid];

        if (nums[left] < nums[mid]) {
            // small big smallest
            if (nums[left] > nums[right]) {
                left = mid + 1;
            } else {
                // small big biggest
                return nums[left];
            }
        } else {
            // big small smallest
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // big small big
                right = mid - 1;
            }
        }
    }

    return nums[left];
}