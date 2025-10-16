#include <iostream>
#include <vector>
using namespace std;

/*
    - Given a sorted array consisting of only integers where every element appears exactly twice,
    except for one element which appears exactly once.
    - Return the single element that appears only once.

    Time: O(logN), Space: O(1)
*/

/*
    Intuition:
    - if mid is even, then it's duplicate should be in next index.
    - if mid is odd, then it's duplicate  should be in previous index.
*/

int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int index = 0;

    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums[0] != nums[1]) return nums[0];
    if (nums[right] != nums[right - 1]) return nums[right];

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid + 1] == nums[mid]) {
            if (mid % 2 == 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else if (nums[mid - 1] == nums[mid]) {
            if (mid % 2 == 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            return nums[mid];
        }
    }

    return -1;
}