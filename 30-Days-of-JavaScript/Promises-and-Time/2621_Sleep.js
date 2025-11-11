/*
    - Given a positive integer millis
    - Write an asynchronous function that sleeps for millis milliseconds. It can resolve any value. 
*/

/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    // returns a new promise that resolves in millis milliseconds with value of nothing
    return new Promise((resolve) => setTimeout(() => resolve(), millis));
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */