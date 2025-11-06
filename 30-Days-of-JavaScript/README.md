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