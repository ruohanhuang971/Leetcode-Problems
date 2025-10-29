/*
    Given a string s
    Find the length of the longest substring without duplicate characters.
*/

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let maxLen = 0;
    let left = 0;
    let right = 0;
    const found = new Map();

    while (right < s.length) {
        // new character or last occurrence is before left border 
        if (!found.has(s[right]) || found.get(s[right]) < left) {
            found.set(s[right], right);
            maxLen = Math.max(right - left + 1, maxLen);
        } else {
            // update left to be after the last occurrence of the current character
            left = found.get(s[right]) + 1;
            found.set(s[right], right);
        }
        right++;
    }

    return maxLen;
};