#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
    - Given an array containing n distinct numbers in the range [0, n]
    - return the only number in the range that is missing from the array.

    Time: O(N^2logN) [loop: O(N), inner while loop: O(N), set insert: O(logN)], Space: O(N)
*/

/*
    Intuition:
    - fix one number at time to reduce the problem to: find two numbers b and c (from the remaining elements) such that b + c = -a
    - sort vector so two-sum can be solved with two pointers:
        - Move left forward to increase sum
        - Move right backward to decrease sum
    - use std::set to avoid duplicates

    Note:
    - unordered_set can have <vector<int>> but set<vector<int>> is okay
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        int target = -nums[i];

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums[left] + nums[right] == target) {
                ans.insert({nums[i], nums[left], nums[right]});
            }
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                left++;
            }
        }
    }

    return vector<vector<int>>(ans.begin(), ans.end());
    ;
}