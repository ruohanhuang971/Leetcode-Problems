#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
    - space is O(h) because the function gets called "depth" amout of times. and in
      the worst case of a complete unbalanced tree, this becomes O(N)
    Reminder: can recursion on this tree
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
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}