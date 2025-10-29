/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']'
    Determine if the input string is valid.
*/

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    const stack = [];
    const p = { ')': '(', '}': '{', ']': '[' };

    for (const n of s) {
        // close
        if (n in p) {
            if (stack[stack.length - 1] != p[n]) return false;
            stack.pop();
        } else {
            // open
            stack.push(n);
        }
    }
    return stack.length === 0;
};