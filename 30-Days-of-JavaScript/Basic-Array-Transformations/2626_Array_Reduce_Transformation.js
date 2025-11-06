/*
    - Given an integer array nums, a reducer function fn, and an initial value init
    - Return the final result obtained by executing the fn function on each element of the array, sequentially, passing in the return value from the calculation on the preceding element.

    - result is achieved through the following operations: 
        - val = fn(init, nums[0])
        - val = fn(val, nums[1])
        - val = fn(val, nums[2])
        - ...
        - return val

    - Please solve it without using the built-in Array.reduce method.
*/

var reduce = function (nums, fn, init) {
    for (const val of nums) {
        init = fn(init, val);
    }
    return init;
};