/*
    - Given an array of integers temperatures represents the daily temperatures
    - Return an array containing the number of days have to wait to get a warmer temperature
*/

/* Time: O(N), Space: O(N) */

/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    const stack = [];
    const ans = new Array(temperatures.length).fill(0);

    for (let i = 0; i < temperatures.length; i++) {
        while (stack.length != 0 && temperatures[stack[stack.length - 1]] < temperatures[i]) {
            const index = stack.pop();
            ans[index] = i - index;
        }
        stack.push(i);
    }
    return ans;
};