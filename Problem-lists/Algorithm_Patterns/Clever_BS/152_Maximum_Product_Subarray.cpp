#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an integer array nums
    - Find a subarray that has the largest product, and return the product.

    Time: O(N), Space: O(1)
*/

/*
    Intuition:
    - Kadane's Algo (Algorithm for maximum subarray problem):
        - Core idea: As you scan left → right, keep a running sum.
        - If the running sum ever goes negative, drop it and start fresh at the next element. Track best sum
        - Why it works: A negative running sum can only hurt future totals—so reset early and often.
    - but for multiplication, negative value flips the current min (-1 => 1) and current max (8 => -8)
    - keep track of both max and min and flip when value is negative
*/

int maxProduct(vector<int>& nums) {
    int global_max = nums[0];
    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    int current_min = nums[0];
    int current_max = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremum by swapping them
        if (nums[i] < 0)
            swap(current_min, current_max);

        // update min/max as either continuing the subarray or starting over
        current_max = max(nums[i], current_max * nums[i]);
        current_min = min(nums[i], current_min * nums[i]);

        global_max = max(global_max, current_max);
    }

    return global_max;
}