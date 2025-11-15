/*
    - Given an object or array obj, return a compact object.

    - A compact object is the same as the original object, except with keys containing falsy values removed. 
    - A value is considered falsy when Boolean(value) returns false.
*/

/*
Intuition:
    - Return primitive values directly unless they are null or undefined.
    - If array, build a new array and recursively compact each element.
    - If object, build a new object that only includes keys whose values compact to something non-null.
*/

/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    if (obj === null || obj === undefined) {
        return;
    } else if (Array.isArray(obj)) {
        const ans = [];
        obj.forEach((x) => {
            if (x) {
                const ret = compactObject(x);
                ans.push(ret);
            }
        });
        return ans;
    } else if (typeof obj === "object") {
        const ans = {};
        for (const key in obj) {
            const ret = compactObject(obj[key]);
            if (ret) {
                ans[key] = ret;
            }
        }
        return ans;
    } else {
        return obj;
    }
};