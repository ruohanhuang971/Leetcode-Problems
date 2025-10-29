/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function (root) {
    if (!root) return [];

    const queue = [];
    queue.push(root);

    const ans = [];
    while (queue.length !== 0) {
        const n = queue.length;
        const temp = [];
        for (let i = 0; i < n; i++) {
            const top = queue.shift();
            temp.push(top.val);

            if (top.left) queue.push(top.left);
            if (top.right) queue.push(top.right);
        }
        ans.push(temp);
    }
    return ans;
};