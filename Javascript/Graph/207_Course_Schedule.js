/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function (numCourses, prerequisites) {
    let adj = Array.from({ length: numCourses }, () => []);
    let numDep = new Array(numCourses).fill(0);

    for (const n of prerequisites) {
        // n[1] is a prerequisites 
        adj[n[1]].push(n[0]);
        // n[0] has one more dependency
        numDep[n[0]]++;
    }

    const queue = [];
    for (let i = 0; i < numCourses; i++) {
        if (numDep[i] === 0) {
            queue.push(i);
        }
    }

    while (queue.length !== 0) {
        const take = queue.shift();

        for (const n of adj[take]) {
            numDep[n]--;
            if (numDep[n] === 0) {
                queue.push(n);
            }
        }
    }

    return Math.max(...numDep) === 0;
};