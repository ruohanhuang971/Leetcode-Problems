#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
    Find the node to delete:
        If no left → return right child
        If no right → return left child
        If both → find rightmost in left subtree, attach right subtree to it, and return left subtree
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
        return NULL;
    if (root->val == key)
        return deleteHelper(root);

    // search for node
    TreeNode* node = root;
    while (node) {
        if (node->val > key) {
            if (node->left && node->left->val == key) {
                node->left = deleteHelper(node->left);
                break;
            }
            node = node->left;
        } else if (node->val < key) {
            if (node->right && node->right->val == key) {
                node->right = deleteHelper(node->right);
            }
            node = node->right;
        }
    }

    return root;
}

TreeNode* deleteHelper(TreeNode* node) {
    // if no child/one child
    if (!node->left) {
        return node->right;
    }
    if (!node->right) {
        return node->left;
    }

    TreeNode* right = node->right;
    TreeNode* lastRight = findLastRight(node->left);
    lastRight->right = right;
    return node->left;
}

TreeNode* findLastRight(TreeNode* root) {
    if (!root->right)
        return root;
    return findLastRight(root->right);
}