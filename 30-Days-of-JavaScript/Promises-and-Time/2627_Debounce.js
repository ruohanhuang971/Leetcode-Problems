/*
    - Given a function fn and a time in milliseconds t
    - Return a debounced version of that function.

    - Debounced function's execution is delayed by t milliseconds
    - execution is cancelled if it is called again within that window of time
*/

var debounce = function (fn, t) {
    let id;
    return function (...args) {
        // a function is queued
        if (id) {
            // reset
            clearTimeout(id);
        }
        // queue new function and update id
        id = setTimeout(() => fn(...args), t);
    }
};