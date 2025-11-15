/*
    - Write code that enhances all arrays such that you can call the array.groupBy(fn) method on any array
    - Return a grouped version of the array.

    - A grouped array is an object where each key is the output of fn(arr[i]) and each value is an array containing 
      all items in the original array which generate that key.

    - The provided callback fn will accept an item in the array and return a string key.
*/

/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function (fn) {
    const ret = {};
    this.forEach((n) => {
        const key = fn(n);
        if (!ret[key]) ret[key] = [];
        ret[key].push(n);
    })
    return ret;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */