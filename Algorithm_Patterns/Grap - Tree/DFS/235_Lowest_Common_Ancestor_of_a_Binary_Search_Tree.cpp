#include <iostream>
#include <vector>
using namespace std;

/*
    - Given a binary search tree (BST)
    - find the lowest common ancestor (LCA) node of two given nodes in the BST.

    Time: O(N), Space: O(N)
*/

/*
    Intuition:
        - each recursive call asks: "What important thing did I find in my subtree?"
    Return values:
        - nullptr = found neither target
        - p or q = found one target node
        - Some ancestor node = found LCA
    Decision logic:
        - Both children return non-null → current node is LCA
        - One child returns non-null → pass it up
        - Both return null → return null
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return root;                   // return nullptr
    if (root == p || root == q) return root;  // return node with either one found

    // if null didn't find anything
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // found one left & one right => return current node
    if (left && right) return root;

    // found on only one branch -> return that branch
    return left ? left : right;
}