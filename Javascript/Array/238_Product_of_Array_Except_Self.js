/*
    Given an integer array nums
    Return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
*/

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
    let numZeros = 0;
    let totalMul = 1;
    for (const n of nums) {
        if (n === 0) {
            numZeros++;
            continue;
        }
        totalMul *= n;
    }

    const ans = new Array(nums.length).fill(0);
    // one 0 -> all 0 except the index of 0
    if (numZeros == 1) {
        ans[nums.indexOf(0)] = totalMul;
        return ans;
    }

    if (numZeros === 0) {
        // divide by cur num
        for (let i = 0; i < nums.length; i++) {
            ans[i] = totalMul / nums[i];
        }
    }

    // 2 or more 0 => all product is 0
    return ans;
};