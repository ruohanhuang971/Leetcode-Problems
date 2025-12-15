// Given: nums array and val
// Return: remove all occurrences of val in nums in-place and return # of integers left in nums

// Time: O(n), space: O(1)

var removeElement = function(nums, val) {
    let pos = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[pos] = nums[i];
            pos++;
        }
    }
    return pos;
};