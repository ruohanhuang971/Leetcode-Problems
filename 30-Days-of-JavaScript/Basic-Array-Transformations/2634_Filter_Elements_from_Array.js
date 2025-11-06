/*
    - Given an integer array arr and a filtering function fn
    - Return a filtered array filteredArr.

    - Please solve it without the built-in Array.filter method.
*/

var filter = function (arr, fn) {
    const newArr = [];
    arr.forEach((val, index) => {
        if (fn(val, index)) newArr.push(val);
    })
    return newArr;
};

var filter = function (arr, fn) {
    return arr.filter((val, index) => fn(val, index));
};