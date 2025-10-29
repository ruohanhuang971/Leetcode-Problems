/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function (s) {
    let seen = new Set();
    let repeated = new Set();
    for (let i = 0; i <= s.length - 10; i++) {
        if (seen.has(s.slice(i, i + 10))) {
            repeated.add(s.slice(i, i + 10));
        } else {
            seen.add(s.slice(i, i + 10));
        }
    }
    return [...repeated];
};