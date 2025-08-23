#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
    - USE REFERNCES YOU DUMB-DUMB
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int goodNodes(TreeNode *root) {
    int ans = 0;
    countGoodNode(root, root->val, ans);

    return ans;
}

void countGoodNode(TreeNode *node, int max, int &ans) {
    if (!node) {
        return;
    }

    if (node->val >= max) {
        ans++;
        max = node->val;
    }

    // cout << node-> val << " " << max << " " << *ans << endl;
    countGoodNode(node->left, max, ans);
    countGoodNode(node->right, max, ans);
}