/*
    Write a function that take in any value val and return an object with the following two functions.
        - toBe(val) accepts another value and returns true if the two values === each other else throw an error "Not Equal".
        - notToBe(val) accepts another value and returns true if the two values !== each other else throw an error "Equal".
*/

var expect = function (val) {
    return {
        toBe: function (v) {
            if (val === v) return true;
            else throw new Error("Not Equal");
        },
        notToBe: function (v) {
            if (val !== v) return true;
            else throw new Error("Equal");
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */