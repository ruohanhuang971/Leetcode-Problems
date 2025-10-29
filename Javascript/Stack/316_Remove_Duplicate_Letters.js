/*
    Given a string s
    Remove duplicate letters so that every letter appears once and only once
        Must make sure result is the smallest in lexicographical order among all possible results.
*/

/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicateLetters = function (s) {
    const stack = [];
    const count = new Map();    // Track remaining count of each letter
    const inStack = new Set();  // Track letters already in stack

    // Step 1: Count how many times each letter appears
    for (const ch of s) {
        count.set(ch, (count.get(ch) ?? 0) + 1);
    }

    // Step 2: Process each letter
    for (const ch of s) {
        // Decrease remaining count
        count.set(ch, count.get(ch) - 1);

        // Skip if already in stack
        if (inStack.has(ch)) continue;

        // Pop letters from stack if they are bigger than current letter
        // AND they will appear later
        while (stack.length && stack[stack.length - 1] > ch && count.get(stack[stack.length - 1]) > 0) {
            const removed = stack.pop();
            inStack.delete(removed);
        }

        // Push current letter
        stack.push(ch);
        inStack.add(ch);
    }

    return stack.join('');
};