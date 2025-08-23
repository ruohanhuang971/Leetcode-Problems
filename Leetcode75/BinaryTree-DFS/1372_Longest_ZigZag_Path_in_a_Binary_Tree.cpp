#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
    I had the right idea for this one. Have two path that go left/right each time
    depending on the direction of the previous node -> start over or keep adding
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int maxStep = 0;
int longestZigZag(TreeNode* root) {
    dfs(root, true, 0);
    dfs(root, false, 0);
    return maxStep;
}
void dfs(TreeNode* root, bool isLeft, int step) {
    if (!root) return;
    maxStep = max(maxStep, step);  // update max step sofar
    if (isLeft) {
        dfs(root->left, false, step + 1);  // keep going from root to left
        dfs(root->right, true, 1);         // restart going from root to right
    } else {
        dfs(root->right, true, step + 1);  // keep going from root to right
        dfs(root->left, false, 1);         // restart going from root to left
    }
}