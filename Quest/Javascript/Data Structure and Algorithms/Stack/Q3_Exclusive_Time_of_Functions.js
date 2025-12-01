/*
    - Given a list logs
    - Return the exclusive time of each function in an 
*/

/**
 * @param {number} n
 * @param {string[]} logs
 * @return {number[]}
 */
var exclusiveTime = function(n, logs) {
    const stack = [];
    let prevTime = 0;
    const ans = new Array(n).fill(0);

    for (const n of logs) {
        const [idStr, type, timeStr] = n.split(':')
        const id = parseInt(idStr);
        const time = parseInt(timeStr);
        if (type === 'start') { // add time to curFunc, update curFunc
            if (stack.length !== 0) {
                ans[stack[stack.length - 1]] += time - prevTime;
            }
            stack.push(id);
            prevTime = time;
        } else {
            const prevFunc = stack.pop();
            ans[prevFunc] += time - prevTime + 1;
            prevTime = time + 1;
        }
    }
    return ans;
};