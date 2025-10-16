#include <iostream>
#include <vector>
using namespace std;

/*
    - Given the root of a binary tree
    - determine if it is a valid binary search tree (BST).

    Time: O(N) [each node visited once], Space: O(N)
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root) {
    return helper(root, 0);
}

int helper(TreeNode *node, int depth) {
    if (!node) return depth;

    depth++;
    return max(helper(node->left, depth), helper(node->right, depth));
}