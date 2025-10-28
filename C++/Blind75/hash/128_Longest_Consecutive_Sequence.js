/**
 * Time: O(N), Space: O(N)
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    const elements = new Set(nums);

    var count = 0;
    var maxCount = 0;
    for (let n of elements) {
        if (!elements.has(n - 1)) {
            count = 1;
            var temp = n;
            while (elements.has(temp + 1)) {
                count++; temp++;
            }
            maxCount = Math.max(maxCount, count);
        }
    }

    return maxCount;
};