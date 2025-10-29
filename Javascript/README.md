# **C++ => Javascript random snippets**

- INT_MIN:
```js
let maxSum = -Infinity;
```

- maxSum = max(maxSum, sum)
```js
maxSum = Math.max(maxSum, sum);
```

- javascript strings
```js
// change case
str1.toUpperCase(); // "HELLO"
str1.toLowerCase(); // "hello"

// reverse
str1.reverse()

// search / checking
const s = "hello world";
s.includes("hello"); // true
s.startsWith("he");  // true
s.endsWith("ld");    // true
s.indexOf("o");      // 4
s.lastIndexOf("o");  // 7

// extract substrings
const s = "abcdef";
s.slice(1, 4);      // "bcd" (end index not included)
s.substring(1, 4);  // "bcd" (similar but no negative index)
s.substr(1, 3);     // "bcd" (deprecated but works)

// trim whitespace
let s = "   spaced   ";
s.trim();       // "spaced"
s.trimStart();  // "spaced   "
s.trimEnd();    // "   spaced"

// convert to array
[...s]
```