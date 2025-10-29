# **Common Functions**

**Traversal**
```js
const arr = [1, 2, 3, 4];

// For loop
for (let i = 0; i < arr.length; i++) {
console.log(arr[i]);
}

// For...of
for (const num of arr) {
console.log(num);
}
```

**Insertion / Deletion**
```js
const arr = [1, 2, 3];

// Add to end
arr.push(4);      // [1, 2, 3, 4]

// Remove from end
arr.pop();        // [1, 2, 3]

// Add to front
arr.unshift(0);   // [0, 1, 2, 3]

// Remove from front
arr.shift();      // [1, 2, 3]

// Remove from middle
arr.splice(1, 1); // remove 1 element at index 1 → [1, 3]

// Insert into middle
arr.splice(1, 0, 2); // insert 2 at index 1 → [1, 2, 3]
```

**Membership**
```js
const arr = [10, 20, 30];

console.log(arr.includes(20)); // true
console.log(arr.indexOf(30));  // 2
```

**Sorting**
```js
const nums = [3, 1, 4, 2];

nums.sort((a, b) => a - b);  // ascending
console.log(nums);           // [1, 2, 3, 4]

nums.sort((a, b) => b - a);  // descending
console.log(nums);           // [4, 3, 2, 1]
```

**Declarations**
```js
// empty array
const arr = [];

// set values
const arr = [1, 2, 3, 4];

// array with fixed size, no default value
const arr = new Array(5);  // [ <5 empty items> ] 

// fixed size && default value
const arr = new Array(5).fill(0); // [0, 0, 0, 0, 0]

// Dynamic Initialization
const arr = Array.from({ length: 5 }, (_, i) => i + 1); // [1, 2, 3, 4, 5]
```