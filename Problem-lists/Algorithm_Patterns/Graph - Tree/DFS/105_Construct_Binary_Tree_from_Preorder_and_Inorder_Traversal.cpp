#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    - Given two integer arrays preorder and inorder traversal of a binary tree
    - Return the binary tree.

    Time: O(N), Space: O(N)
*/

/*
    Intuition:
    - step 1: build Inorder Index Map: find index of a value in O(1) time
    - step 2: identify current root
        - first element in preorder is always the root of the current subtree
    - step 3: find root in inorder with the Index Map
        - this divides the tree into the left and right subtree
    - Step 4: recursively Build Subtrees
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inmap;
    for (int i = 0; i < inorder.size(); i++) {
        inmap[inorder[i]] = i;
    }

    int preIndex = 0;
    return helper(preorder, inorder, inmap, preIndex, 0, preorder.size());
}

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inmap, int& preIndex, int start, int end) {
    if (start >= end) return nullptr;

    // the first index of preorder is the root
    TreeNode* root = new TreeNode(preorder[preIndex]);
    // where the first index is in inorder split the tree into left and right
    int index = inmap[root->val];
    // after every node, increment the position in preorder
    preIndex++;

    // build left and right branch of tree
    root->left = helper(preorder, inorder, inmap, preIndex, start, index);
    root->right = helper(preorder, inorder, inmap, preIndex, index + 1, end);

    return root;
}