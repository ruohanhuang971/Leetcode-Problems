# **Queue**
- Property: LIFO
- Note: queue in javascript is still just an array
```js
const queue = [];

// Enqueue
queue.push(1);
queue.push(2);
queue.push(3);
console.log(queue); // [1, 2, 3]

// Peek
console.log(queue[0]); // 1

// Dequeue
queue.shift(); // removes 1
console.log(queue); // [2, 3]

// Check empty
console.log(queue.length === 0); // false
```