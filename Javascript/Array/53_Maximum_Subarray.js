/*
    Given an integer array nums
    Find the subarray with the largest sum, and return its sum.
*/

var maxSubArray = function (arr) {
    let n = arr.length;
    let maxSum = -Infinity;
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum = sum + arr[i];
        if (sum > maxSum) maxSum = Math.max(maxSum, sum);

        if (sum < 0) sum = 0;
    }
    return maxSum;
};