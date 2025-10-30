/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function (intervals, newInterval) {
    const ans = [];
    // find first interval that overlaps
    let index = 0;
    while (index < intervals.length && newInterval[0] > intervals[index][1]) {
        ans.push(intervals[index]);
        index++;
    }

    // find last interval that overlaps
    while (index < intervals.length && newInterval[1] >= intervals[index][0]) {
        newInterval = [Math.min(newInterval[0], intervals[index][0]), Math.max(newInterval[1], intervals[index][1])];
        index++;
    }

    ans.push(newInterval);

    while (index < intervals.length) {
        ans.push(intervals[index]);
        index++;
    }

    return ans;
};