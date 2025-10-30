#include <iostream>
#include <vector>
using namespace std;

/*
    - Given the root of a binary tree
    - Return the maximum path sum of any non-empty path [path does not need to pass through the root and can start at any node]

    Time: O(N), Space: O(N)
*/

/*
    Intuition:
    - postorder DFS traversal (visit all children before processing current node)
    - At each node:
        - Recursively compute the max gain from the left and right children [Ignore negative gains]
        - Update the global max (ans) with the path going through this node: node.val + leftGain + rightGain.
        - Return to the parent: node.val + max(leftGain, rightGain) since parent can only continue on one side.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    helper(root, ans);
    return ans;
}

int helper(TreeNode* node, int& ans) {
    if (!node) return 0;

    // for each node there are 4 options
    // currentNode, left path + currentNode, right path + currentNode, left path + currentNode + right path
    int left = max(helper(node->left, ans), 0);
    int right = max(helper(node->right, ans), 0);

    ans = max(ans, left + node->val + right);

    // return max gain when passing through this node -> can only pick one path
    return node->val + max(left, right);
}