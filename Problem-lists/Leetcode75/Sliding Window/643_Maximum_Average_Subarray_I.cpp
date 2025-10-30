#include <iostream>
#include <vector>
using namespace std;

/*
    Sliding window approach:
        1. increase the size of window until len become k
        2. slide the window only

    Time Complexity: O(N), Space Complexity: O(1)
*/

double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int curSum = 0;
        int start = 0;

        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            
            if(i - start + 1 == k){
                maxSum = max(maxSum, curSum);
                curSum -= nums[start];
                start++;
            }
        }

        return (double)maxSum / k;
    }