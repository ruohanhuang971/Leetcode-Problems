# **Stack**
- Property: LIFO
- Note: stack in javascript is still just an array

**Common Stack Operations**
```js
const stack = [];

// Push elements
stack.push(10); // [10]
stack.push(20); // [10, 20]
stack.push(30); // [10, 20, 30]

// Top
console.log(stack[stack.length - 1]); // 30

// Pop
stack.pop(); // [10, 20]

// Check if empty
console.log(stack.length === 0); // false
```