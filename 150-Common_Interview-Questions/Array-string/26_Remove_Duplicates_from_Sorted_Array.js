// Given: sorted integer array
// Return: remove the duplicates in-place, return number of unique elements

// Time: O(n), space: O(1)

var removeDuplicates = function(nums) {
    let pos = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[i - 1]) {
            nums[pos] = nums[i];
            pos++;
        }
    }
    return pos;
};