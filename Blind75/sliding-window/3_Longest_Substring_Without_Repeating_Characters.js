/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let start = 0
    var seq = new Set()
    let cur_len = 0
    let max_len = 0
    for (let n of s) {
        if (!seq.has(n)) { // not duplicate
            seq.add(n)
            cur_len++;
        } else {
            while (s[start] != n) {
                seq.delete(s[start]);
                start++;
                cur_len--;
            }
            start++;
        }
        max_len = Math.max(max_len, cur_len);
    }

    return max_len;
};