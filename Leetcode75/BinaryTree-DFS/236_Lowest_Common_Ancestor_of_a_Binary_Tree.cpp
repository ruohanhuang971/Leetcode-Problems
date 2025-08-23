#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
    Intuation:
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
    if (!root || root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both left and right found something, current node is LCA
    if (left && right) {
        return root;
    }

    // Otherwise return whichever subtree found something
    return left ? left : right;
}