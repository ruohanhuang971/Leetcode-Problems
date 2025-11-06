/*
    Write a function that accept an initial integer init. It should return an object with three functions.
        - increment() increases the current value by 1 and then returns it.
        - decrement() reduces the current value by 1 and then returns it.
        - reset() sets the current value to init and then returns it.
*/

var createCounter = function (init) {
    let curVal = init;
    return {
        increment: function () {
            return ++curVal;
        },
        decrement: function () {
            return --curVal;
        },
        reset: function () {
            curVal = init;
            return curVal;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */