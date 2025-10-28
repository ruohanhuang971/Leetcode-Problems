#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(logN), Space: O(1)
*/

int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1) return 0;

    int left = 1;
    int right = nums.size() - 2;
    int mid = (right - left) / 2 + left;

    if (nums[left] < nums[left - 1]) return 0;
    if (nums[right] < nums[right + 1]) return nums.size() - 1;

    while (left <= right) {
        mid = (right - left) / 2 + left;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            return mid;
        }

        if (nums[mid + 1] > nums[mid]) {
            left = mid + 1;
        } else if (nums[mid - 1] > nums[mid]) {
            right = mid - 1;
        }
    }

    return mid;
}