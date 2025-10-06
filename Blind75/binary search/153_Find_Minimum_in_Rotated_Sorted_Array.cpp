#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(log N) [binary search], Space: O(1)
    Intuition:
    - Array was originally in ascending order. Now that the array is rotated, there is  a point in the array where there is a
     small deflection from the increasing sequence. eg. [4, 5, 6, 7, 0, 1, 2].
    - All the elements to the left of inflection point > first element of the array.
    - All the elements to the right of inflection point < first element of the array.
*/

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int firstElem = nums[0];

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= firstElem) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return min(nums[left], firstElem);
}