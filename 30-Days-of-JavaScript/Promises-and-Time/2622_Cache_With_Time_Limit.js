/*
    - Write a class that allows getting and setting key-value pairs, however a time until expiration is associated with each key.

    - The class has three public methods:
        - set(key, value, duration): accepts an integer key, an integer value, and a duration in milliseconds.
        - get(key): if an un-expired key exists, it should return the associated value. Otherwise it should return -1.
        - count(): returns the count of un-expired keys.
*/

/*
    Intuition:
    - use Map to store keys, data, and id to setTimeout
        - setTimeout automatically remove key after duration expires
    - set():
        - If the key exists, clear the old timeout using clearTimeout().
        - Create a new setTimeout() that will delete the key after the given duration.
        - Store the new [value, timeoutId] pair in the map.
        - Return whether the key was already present (unexpired).
    - get() simply checks if the key exists and returns the value or -1.
    - count() returns the current number of entries in the map — since expired ones are automatically removed, this is always accurate.
 */

var TimeLimitedCache = function () {
    this.m = new Map();
};

TimeLimitedCache.prototype.set = function (key, value, duration) {
    const exists = this.m.has(key);

    if (exists) {
        clearTimeout(this.m.get(key)[1]); // cancel old timer
    }

    const id = setTimeout(() => this.m.delete(key), duration);
    this.m.set(key, [value, id]);

    return exists;
};

TimeLimitedCache.prototype.get = function (key) {
    return this.m.has(key) ? this.m.get(key)[0] : -1;
};

TimeLimitedCache.prototype.count = function () {
    return this.m.size;
};
