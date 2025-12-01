/*
    - You are given an integer array target and an integer n.
    - Use the two stack operations to make the numbers in the stack equal to target
*/

/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function(target, n) {
    let curIndex = 0;
    const ans = [];
    for (let i = 1; i <= n; i++) {
        if (curIndex >= target.length) break;
        if (i != target[curIndex]) {
            ans.push('Push');
            ans.push('Pop');
        } else {
            ans.push('Push');
            curIndex++;
        }
    }
    return ans;
};