#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode *root) {
    if (!root) {
        return vector<int>();
    }

    queue<TreeNode *> visit;
    vector<int> ans;
    visit.push(root);

    while (!visit.empty()) {
        int size = visit.size();
        for (int i = 0; i < size; i++) {
            TreeNode *node = visit.front();

            if (node->left) {
                visit.push(node->left);
            }
            if (node->right) {
                visit.push(node->right);
            }

            if (i == size - 1) {
                ans.push_back(node->val);
            }
            visit.pop();
        }
    }

    return ans;
}