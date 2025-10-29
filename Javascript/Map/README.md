# **Hash Map (Map)**
- collection of key-value pairs

**declaration**
```js
// declare new map
const map = new Map();
```

**common functions**
```js
// Set key-value
map.set('a', 1);
map.set('b', 2);

// Get value
map.get('a'); // 1

// Check existence
map.has('b'); // true

// Delete a key
map.delete('a');

// Size of the map
map.size; // 1

map.clear(); // removes all entries
```

**Iterate**
```js
// Iterate over entries
for (const [key, value] of map) {
    ...
}
```

**Get keys/values**
- function return a iterator over the map, [...x] make it into an array
```js
const keys = [...map.keys()]; // ['a', 'b']
const values = [...map.values()]; // [1, 2]
const entries = [...map.entries()]; // [['a', 1], ['b', 2]]
```