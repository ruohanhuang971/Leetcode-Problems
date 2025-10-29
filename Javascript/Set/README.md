# **Set**

**Constructor**
```js
const set = new Set();
```

**Common Operations**
```js
Copy code
// Add values
set.add(1);
set.add(2);
set.add(2); // duplicates ignored

// Check existence
set.has(1); // true

// Delete a value
set.delete(2);

// Size of set
set.size; // 1

// Iterate over set
for (const val of set) {
    console.log(val);
}
// Output: 1
```