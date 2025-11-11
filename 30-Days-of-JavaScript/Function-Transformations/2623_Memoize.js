/*
    - Given a function fn
    - Return a memoized version of that function.

    - A memoized function is a function that will never be called twice with the same inputs. Instead it will return a cached value.
*/

/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const seenInput = new Map;

    return function (...args) {
        const key = JSON.stringify(args);

        if (seenInput.has(key)) {
            return seenInput.get(key);
        }
        const ans = fn(...args);
        seenInput.set(key, ans); // add to cache
        return ans;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */