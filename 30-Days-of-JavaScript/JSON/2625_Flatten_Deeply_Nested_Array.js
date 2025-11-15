/*
    - Given a multi-dimensional array arr and a depth n, return a flattened version of that array.

    - A flattened array is a version of that array with some or all of the sub-arrays removed 
      and replaced with the actual elements in that sub-array
*/

// recursion:
var flat = function (arr, n) {
    if (n === 0) return arr;

    const ans = [];
    arr.forEach((x) => {
        if (Array.isArray(x)) {
            const nested = flat(x, n - 1); // Recursively flatten nested arrays
            ans.push(...nested); // Concatenate flattened nested arrays to the result
        } else {
            ans.push(x);
        }
    });

    return ans;
};