## **Closures**

-  In JavaScript, functions have a reference to all variables declared in the same scope as well as any outer scopes. These scopes are known as the function's lexical environment
- The combination of the function and it's environment is known as a closure.

- Example:
    - In Javascript, you can declare functions within other functions and return them. The inner function has access to any variables declared above it. 
    - The inner function add has access to a
        ```js
        function createAdder(a) {
            return function add(b) {
                const sum = a + b;
                return sum;
            }
        }
        const addTo2 = createAdder(2);
        addTo2(5); // 7
        ```

## **Returning an object with methods**
- example:
    - return an object with two 2 methods, toBe() and notToBe()
    ```js
    var expect = function(val) {
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
    ```

## **For loop access**
- For each:
    ```js
    arr.forEach((value, index) => {
        console.log(index, value);
    });
    ```
- entries():
    ```js
    for (const [index, value] of arr.entries()) {
        console.log(index, value);
    }
    ```
    - also work for objects:
        ```js
        for (const [key, value] of Object.entries(obj)) {
            console.log(key, value);
        }
        ```

## **Promise**
- Example:
    ```js
    const promise = new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve("✅ Done!");
        }, 1000);
    });

    promise.then(result => console.log(result));
    ```
    - When creating a promise, give it an executor function [(resolve, reject) => { ... }]
        - JavaScript immediately runs that function
        - it gives the function resolve and reject which determine when and how the promise finishes
    - after 1000 milliseconds, after setTimeout times out, resolve is called with the value of "Done!"
    - promise.then() waits until promise is resolve and run the function with the resolved value
- Async function automatically return a promise
    - so returning a number means the promise will resolve with that number
        ```js
        var addTwoPromises = async function(promise1, promise2) {
            const num1 = await promise1;
            const num2 = await promise2;
            return num1 + num2;  // async functions automatically wrap return in a Promise
        };
        ```
    - but that promise resolves immediately when the function’s body finishes.
- **Promise.all**: wait for multiple promises 
    ```js
    var addTwoPromises = function(promise1, promise2) {
        return Promise.all([promise1, promise2])
            .then(([num1, num2]) => num1 + num2);
    };
    ```
- **Promise.race()**: races multiple Promises
    - whichever settles first (resolve or reject) decides the final outcome.
    ```js
    async function(...args) {
        // race two promises
        const timeout = new Promise((resolve, reject) => {
            setTimeout(() => reject("Time Limit Exceeded"), t);
        });
        const succeed = fn(...args);

        return Promise.race([succeed, timeout]);
    }
    ```

## **setTimeout**

- setTimeout(fn, t) takes two parameters: callback function + delay milliseconds
    - callback function is execute after the delay
- process:
    - after calling setTimeout, the callback function is registered and a timer is started
    - after the timer end, the callback function is added to the event queue
    - the task in the event queue is executed after the call stack is empty -> all other code to be run while waiting for the timer to end
- clearTimeout(id):
    - cancels a timeout previously set with setTimeout by passing the timeout ID returned by setTimeout

## **Prototypes**
- every JavaScript object has a hidden internal link called [[Prototype]].
    - this is another “parent” object from which this object can inherit properties and methods
    ```js
    const obj = {};
    console.log(Object.getPrototypeOf(obj));
    ```
- **Prototype Chain**
    - when accessing a property, if it isn’t found directly on an object, JS automatically looks for it up the prototype chain.
    ```js
    const animal = { eats: true };
    const dog = Object.create(animal);
    dog.barks = true;

    console.log(dog.eats); // true (inherited)
    ```
- **Constructor Functions & Prototypes**
    ```js
    function Dog(name) { this.name = name; }
    Dog.prototype.bark = function() { console.log("Woof"); };

    const d1 = new Dog("Rex");
    const d2 = new Dog("Spot");

    d1.bark === d2.bark; // true (shared function)
    ```
    - can access it from any prototype method
    - **instance property**
        - created inside constructor with this.x = ...
            - not shared with other instance
    - **Prototype property**
        - stored with Func.prototype
            - shared across all instances
- **Checking Inheritance**
    ```js
    rex instanceof Dog;     // true
    rex instanceof Animal;  // true
    Dog.prototype.isPrototypeOf(rex); // true
    ```

## **JSON**
- consists of two main data structures: objects{} and arrays[]
    - keys in an object must be strings, while the values can be any valid JSON data type, including objects and arrays
- **JSON.parse():**
    - converts a JSON string into a JavaScript object, array or a primitive value (such as a string, number, boolean, or null)
- **JSON.stringify**
    - convert the input array/object to a string. If the array or object is empty, it returns a string with opening and closing braces or curly braces.

## **Classes**
- blueprint for creating objects that share: properties (data) & methods (functions)
- example:
    ```js
    class Animal {
        // constructor: initialize the object
        constructor(name) {
            // this refers to the object being created
            this.name = name; // property
        }

        // property can also be defined like this
        name = name;


        // all objects created from the class have access to this method
        speak() {            // method on the prototype
            console.log(this.name + " makes a sound.");
        }
    }

    const dog = new Animal("Fido");
    dog.speak(); // "Fido makes a sound."
    ```

## **Random Notes**
- Array can be a key in a Map but it is treated by reference, not by value
    - to use array as key, use JSON.stringify(arr)
    - ex:
        ```js
        function memoize(fn) {
            const cache = new Map();

            return function(...args) {
                const key = JSON.stringify(args);
                if (cache.has(key)) return cache.get(key);

                const result = fn(...args);
                cache.set(key, result);
                return result;
            };
        }
        ```
- Check if an object is an Array or an object:
    ```js
    if (Array.isArray(value)) {
        // array
    }

    if (typeof value === "object") {
        // object
    }
    ```