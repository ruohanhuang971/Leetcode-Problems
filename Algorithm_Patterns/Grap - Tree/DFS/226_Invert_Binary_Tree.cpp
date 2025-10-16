#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    - There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
    - given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take
      course bi first if you want to take course ai.
    - Return true if you can finish all courses. Otherwise, return false.

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

TreeNode *invertTree(TreeNode *root) {
    if (!root) return root;

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}