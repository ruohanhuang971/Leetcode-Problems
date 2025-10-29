/*
    Given an array of strings strs
    Group the anagrams together.
*/

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
    const map = new Map();

    for (const n of strs) {
        const key = n.split('').sort().join('');
        if (!map.has(key)) map.set(key, []);
        map.get(key).push(n);
    }

    return [...map.values()];
};