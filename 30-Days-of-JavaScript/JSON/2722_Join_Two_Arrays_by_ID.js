/*
    - Given two arrays arr1 and arr2, return a new array joinedArray. 
    - All the objects in each of the two inputs arrays will contain an id field that has an integer value. 

    - joinedArray is an array formed by merging arr1 and arr2 based on their id key. 
    - The length of joinedArray should be the length of unique values of id. 
    - The returned array should be sorted in ascending order based on the id key.

    If two objects share an id, their properties should be merged into a single object:
        - If a key only exists in one object, that single key-value pair should be included in the object.
        - If a key is included in both objects, the value in the object from arr2 should override the value from arr1.
*/

/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
    const map = new Map();

    arr1.forEach((x) => {
        map.set(x.id, x);
    })
    arr2.forEach((x) => {
        if (map.has(x.id)) {
            map.set(x.id, { ...map.get(x.id), ...x });
        } else {
            map.set(x.id, x);
        }
    })
    const arr = [];
    for (let val of map.values()) {
        arr.push(val);
    }
    arr.sort((a, b) => a.id - b.id);
    return arr;
};