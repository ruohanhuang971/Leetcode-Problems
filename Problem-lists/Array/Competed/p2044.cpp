/*
    Prompt: Given an integer array nums, find the maximum possible bitwise OR of a subset of nums 
    and return the number of different non-empty subsets with the maximum bitwise OR.

    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) 
    elements of b. Two subsets are considered different if the indices of the elements chosen are different.

    The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).
*/

#include <iostream>
#include <vector>
using namespace std;

int subsetOr(int i, vector<int>& nums, int currentOr, int maxOr) {
    // end of subset
    if (i == nums.size()) {
        if (currentOr == maxOr) {
            return 1;
        }
        return 0;
    }
    
    // include current value  
    int countWithout = subsetOr(i+1, nums, currentOr, maxOr);
    
    // exclude the current value
    int countWith = subsetOr(i+1, nums, currentOr | nums[i], maxOr);

    return countWithout + countWith;
}

int countMaxOrSubsets(vector<int>& nums) {
    int maxOrVal = 0;
    for (int num : nums) {
        maxOrVal |= num;
    }

    return subsetOr(0, nums, 0, maxOrVal);
}

int main() {
    vector<int> nums = {3,2,1,5};
    int ans = countMaxOrSubsets(nums);
    cout << ans << endl;
}