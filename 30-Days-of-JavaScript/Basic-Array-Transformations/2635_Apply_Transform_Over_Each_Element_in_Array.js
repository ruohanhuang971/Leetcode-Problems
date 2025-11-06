/*
- Given an integer array arr and a mapping function fn
- return a new array with a transformation applied to each element.

- The returned array should be created such that returnedArray[i] = fn(arr[i], i).

- Please solve it without the built-in Array.map method
*/


// not using map
var map = function (arr, fn) {
    const newArr = new Array(arr.length);
    for (let i = 0; i < arr.length; i++) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr;
};

// using map
var map = function (arr, fn) {
    return arr.map((i, index) => fn(i, index));
};