// Given: sorted integer array
// Return: remove duplicates in-place so each unique element appears at most twice. return new length

// Time: O(n), space: O(1)

var removeDuplicates = function(nums) {
    let occ = 1;
    let pos = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] === nums[i - 1] && occ < 2) {
            nums[pos] = nums[i];
            pos++;
            occ++;
        } else if (nums[i] !== nums[i - 1]) {
            nums[pos] = nums[i];
            pos++;
            occ = 1;
        }
    }
    return pos;
};