#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size());
    }

    TreeNode* constructTree(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nullptr;
        }

        // find max
        int max = nums[start];
        int maxIndex = start;
        for (int i = start; i < end; i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }

        TreeNode* node = new TreeNode(max);
        node->left = constructTree(nums, start, maxIndex);
        node->right = constructTree(nums, maxIndex + 1, end);

        return node;
    }
};