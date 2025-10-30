#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N^2), Space: O(N)
    intuition:
        1. Count all paths that START from the current root
        2. Count all paths in the left subtree (that don't involve root)
        3. Count all paths in the right subtree (that don't involve root)
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;

    return countPathsFromNode(root, targetSum) +  // paths starting from root
           pathSum(root->left, targetSum) +       // paths entirely in left subtree
           pathSum(root->right, targetSum);       // paths entirely in right subtree
}

int countPathsFromNode(TreeNode* node, long long remainingSum) {
    if (!node) return 0;

    int pathCount = 0;

    // Check if this single node equals the target
    if (node->val == remainingSum) {
        pathCount = 1;
    }

    // check paths that continue beyond this node
    // subtract current node's value to find what value is still needed
    pathCount += countPathsFromNode(node->left, remainingSum - node->val);
    pathCount += countPathsFromNode(node->right, remainingSum - node->val);

    return pathCount;
}