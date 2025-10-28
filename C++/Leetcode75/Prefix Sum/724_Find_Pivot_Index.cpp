#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int rightSum = accumulate(nums.begin(), nums.end(), 0); // Initialize rightSum to sum of all numbers
    int leftSum = 0;

    for (int idx = 0; idx < nums.size(); idx++) {
        rightSum -= nums[idx]; // subtract current elements from rightSum

        if (leftSum == rightSum)
            return idx;
        
        leftSum += nums[idx]; // add current elements to leftSum
    }
    return -1;
}