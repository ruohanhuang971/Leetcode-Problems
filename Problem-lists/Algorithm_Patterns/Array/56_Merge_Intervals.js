/*
    Time: O(nlogn), space: O(n)
*/

/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
    const ans = [];

    // sort by start time
    intervals.sort((a, b) => a[0] - b[0]);

    for (const [start, end] of intervals) {
        if (ans.length > 0 && ans[ans.length - 1][1] >= start) {
            ans[ans.length - 1][1] = Math.max(ans[ans.length - 1][1], end);
        } else {
            ans.push([start, end]);
        }
    }

    return ans;
};