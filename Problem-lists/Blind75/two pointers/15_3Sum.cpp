#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
    Time: (O(N²logN)), Space: O(N)
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    // set + two pointer method
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    for (int start = 0; start < nums.size(); start++) {
        int mid = start + 1;
        int end = nums.size() - 1;
        while (mid < end) {
            int sum = nums[start] + nums[mid] + nums[end];
            if (sum == 0) {
                s.insert({nums[start], nums[mid], nums[end]});
                mid++;
                end--;
            } else if (sum > 0) {
                end--;
            } else {
                mid++;
            }
        }
    }

    return vector<vector<int>>(s.begin(), s.end());
}