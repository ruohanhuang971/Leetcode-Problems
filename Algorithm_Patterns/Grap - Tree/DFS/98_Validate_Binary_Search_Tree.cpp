#include <iostream>
#include <vector>
using namespace std;

/*
    - Given the root of a binary tree
    - determine if it is a valid binary search tree (BST).

    Time: O(N) [each node visited once], Space: O(N)
*/

/*
    Note:
    - each iteration update min and max value for that node based on if its going left or right
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode *root) {
    return helper(root, LONG_MIN, LONG_MAX);
}

bool helper(TreeNode *node, long long min, long long max) {
    if (!node) return true;

    if (node->val <= min || node->val >= max) return false;

    return helper(node->left, min, node->val) && helper(node->right, node->val, max);
}