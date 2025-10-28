/*
    Prompt: Given a zero-based permutation nums (0-indexed), build an array ans of the same length where 
    ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
    A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).
*/

#include <iostream>
#include <vector>

/*
    Time complexity: O(n).
    Space complexity: O(1).
*/

using namespace std;

vector<int> buildArray(vector<int>& nums) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        ans.push_back(nums[nums[i]]);
    }

    return ans;
}

void printArray(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << "\n";
}

int main () {
    vector<int> nums = {0,2,1,5,3,4};

    vector<int> ans = buildArray(nums);
    printArray(ans);
}

