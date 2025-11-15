/*
    - Design an EventEmitter class with two methods:
        - subscribe (name of an event as a string and a callback function)
            - the callback function will later be called when the event is emitted.
            - also return an object with an unsubscribe method that removes the callback
        - emit (name of an event as a string and an optional array of arguments)
            - if there are no callbacks subscribed to the given event, return an empty array
            - otherwise, return an array of the results of all callback calls in the order they were subscribed.
*/

class EventEmitter {
    m = {};

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if (!this.m[eventName]) this.m[eventName] = [];
        this.m[eventName].push(callback);

        return {
            unsubscribe: () => {
                this.m[eventName] = this.m[eventName].filter((x) => x !== callback);
            }
        };
    }

    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if (!this.m[eventName]) return [];

        const ans = [];
        for (let i = 0; i < this.m[eventName].length; i++) {
            // if (args.length > i) {
            //     ans.push(this.m[eventName][i](args);
            // }
            ans.push(this.m[eventName][i](...args));
        }
        return ans;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */