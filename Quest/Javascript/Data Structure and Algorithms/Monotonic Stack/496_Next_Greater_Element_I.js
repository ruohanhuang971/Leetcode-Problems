/*
    - You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
    - Return an array ans of length nums1.length such that ans[i] is the next greater element of that value in nums2.
*/

/* Time: O(N + M) Space: O(N + M)   N = num1, M = nums2 */
var nextGreaterElement = function(nums1, nums2) {
    const nextGreater = new Map();
    const stack = [];
    for (const n of nums2) {
        while(stack.length !== 0 && n > stack[stack.length - 1]) {
            nextGreater.set(stack.pop(), n);
        }
        stack.push(n);
    }

    const ans = [];
    for (const n of nums1) {
        if (nextGreater.get(n)) ans.push(nextGreater.get(n));
        else ans.push(-1);
    }

    return ans;
};