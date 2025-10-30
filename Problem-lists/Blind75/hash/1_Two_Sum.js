/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

/**
 * Time: O(N), Space: O(N)
 */

var twoSum = function (nums, target) {
    let map = new Map()
    for (let i = 0; i < nums.length; i++) {
        var remainder = target - nums[i];
        if (map.has(remainder)) {
            return [i, map.get(remainder)]
        }
        map.set(nums[i], i);
    }
};