/*
    - Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0])
    - Return the next greater number for every element in nums.
*/

/* Time: O(N), Space: O(N) */

var nextGreaterElements = function(nums) {
    const ans = new Array(nums.length).fill(-1);
    const stack = [0];
    let index = 1;

    while (stack.length != 0 && index < stack[0] + nums.length + 1) {
        while (stack.length != 0 && nums[index % nums.length] > nums[stack[stack.length - 1]]) {
            const i = stack.pop();
            ans[i] = nums[index % nums.length];
        }
        stack.push(index % nums.length);
        index++;
    }
    return ans;
};