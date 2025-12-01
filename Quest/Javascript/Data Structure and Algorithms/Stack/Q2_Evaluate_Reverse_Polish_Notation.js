/*
    - You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
    - Return an integer that represents the value of the expression.
*/

/**
 * @param {string[]} tokens
 * @return {number}
 */
const op = {
    '+': function add(x, y) { return x + y; },
    '-': function sub(x, y) { return x - y; },
    '*': function mul(x, y) { return x * y; },
    '/': function div(x, y) { return (x / y) >> 0; },
};

var evalRPN = function(tokens) {
    let ans = 0;
    const stack = [];
    let index = 0;
    for (const n of tokens) {
        const z = parseInt(n, 10);
        if (Number.isNaN(z)) {
            const second = stack.pop();
            const first = stack.pop();
            // console.log(second, first)
            stack.push(op[n](first, second));
        } else {
            stack.push(z);
        }
    }
    return stack[0];
};