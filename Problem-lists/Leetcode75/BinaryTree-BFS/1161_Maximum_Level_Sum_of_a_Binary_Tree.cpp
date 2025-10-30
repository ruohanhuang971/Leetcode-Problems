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

int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> visit;
    visit.push(root);

    int max = INT_MIN;
    int max_index = 0;
    int index = 1;
    while (!visit.empty()) {
        int size = visit.size();
        int cur_sum = 0;
        for (int i = 0; i < size; i++) {
            TreeNode *node = visit.front();

            visit.pop();
            cur_sum += node->val;

            if (node->left) {
                visit.push(node->left);
            }

            if (node->right) {
                visit.push(node->right);
            }
        }
        if (max < cur_sum) {
            max = cur_sum;
            max_index = index;
        }
        index++;
    }

    return max_index;
}