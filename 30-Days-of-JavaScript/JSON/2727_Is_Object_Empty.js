/*
    - Given an object or an array
    - Return if it is empty.
*/

/*
* If it is empty: return '()' or '{}' so check if the length of string is longer than that
*/

/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function (obj) {
    console.log(JSON.stringify(obj))
    return JSON.stringify(obj).length <= 2;
};