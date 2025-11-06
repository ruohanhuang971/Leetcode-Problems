/*
    Write a function that return a new function that always returns "Hello World".
*/

var createHelloWorld = function () {

    return function (...args) {
        return "Hello World"
    }
};