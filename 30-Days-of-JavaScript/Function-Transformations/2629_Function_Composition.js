/*
    - Given an array of functions [f1, f2, f3, ..., fn]
    - Return a new function fn that is the function composition of the array of functions.

    - The function composition of [f(x), g(x), h(x)] is fn(x) = f(g(h(x))).
*/

/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {

    return function (x) {
        return functions.reduceRight((acc, cur) => cur(acc), x);
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */