/*
    - Given an array of asynchronous functions
    - Return a new promise. Each function in the array accepts no arguments and returns a promise. All the promises should be executed in parallel.

    - promise resolves:
        - When all the promises returned from functions were resolved successfully in parallel. 
        - The resolved value of promise is array of all the resolved values of promises in the same order as they were in the functions.
    - promise rejects:
        - if any promises reject

Please solve it without using the built-in Promise.all function.
*/

/*
    Intuition:
        - Create and return one Promise.
        - Inside it, start all the functions.
        - For each one:
            - When it succeeds [.then()] → store result and increment counter.
            - If it fails [.catch()] → reject immediately.
            - If all succeed [if (completed === functions.length)] → resolve with the results array.
*/

/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
    return new Promise((resolve, reject) => {
        const ans = new Array(functions.length);
        let completed = 0;
        for (let i = 0; i < functions.length; i++) {
            // run the function
            functions[i]().then((ret) => {
                ans[i] = ret;
                completed++;
                if (completed === functions.length) resolve(ans);
            }).catch((err) => reject(err));
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */