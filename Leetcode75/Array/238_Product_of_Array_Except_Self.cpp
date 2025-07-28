#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Options 1: Time complexity O(n), space complexity O(1)
        1. calculate product of the whole array and for each element in nums, divide the product by nums[i]
            a. If there are more than one 0s in nums, the result is an array consisting of all 0.
            b. If there is a single 0 in nums, then the result is an array consisting of all 0 except at the index where there was 0 in nums
            c. If there's no 0 in nums, then the result is an array ans where ans[i] = prod / nums[i]
*/
vector<int> productExceptSelf(vector<int>& nums) {
    int prod = 1, zeroCnt = count(begin(nums), end(nums), 0);
    if (zeroCnt > 1)
        return vector<int>(size(nums));  // Case-1
    for (auto c : nums)
        if (c)
            prod *= c;  // calculate product of all elements except 0
    for (auto& c : nums)
        if (zeroCnt)
            c = c ? 0 : prod;  // Case-2
        else
            c = prod / c;  // Case-3
    return nums;
}

/*
    Option 2: Time complexity O(n), space complexity O(n)
    - calculate Prefix Product Array and Suffix Product Array and the multiply those
*/

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    vector<int> leftProduct(n);
    vector<int> rightProduct(n);

    leftProduct[0] = 1;
    for (int i = 1; i < n; i++) {
        leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
    }

    rightProduct[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++) {
        ans[i] = leftProduct[i] * rightProduct[i];
    }

    return ans;
}