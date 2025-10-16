#include <iostream>
#include <vector>
using namespace std;

/*
    - Given the root of a binary search tree, and an integer k
    - return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

    Time: O(N), Space: O(N)
*/

/*
    Note:
    - Use recursive inorder traversal -> keep going left and go right once node == nullptr
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) {
    int ans = 0;
    helper(root, k, ans);

    return ans;
}

void helper(TreeNode* node, int& k, int& ans) {
    if (!node) return;
    helper(node->left, k, ans);
    k--;
    if (k == 0) {
        ans = node->val;
        return;
    }
    helper(node->right, k, ans);
}