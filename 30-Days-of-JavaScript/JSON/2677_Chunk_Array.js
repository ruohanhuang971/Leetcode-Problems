/*
    - Given an array arr and a chunk size size
    - Return a chunked array.

    - A chunked array contains the original elements in arr, but consists of subarrays each of length size
    - The length of the last subarray may be less than size if arr.length is not evenly divisible by size.
*/

/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function (arr, size) {
    const ans = [];
    for (let i = 0; i < arr.length; i += size) {
        ans.push(arr.slice(i, i + size));
    }

    return ans;
};
