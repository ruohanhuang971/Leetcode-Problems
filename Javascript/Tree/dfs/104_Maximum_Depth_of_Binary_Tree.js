/*
    Classic DFS
*/

var maxDepth = function (root) {
    if (!root) return 0;

    const left = 1 + maxDepth(root.left);
    const right = 1 + maxDepth(root.right);

    return Math.max(left, right);
};