#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

/*
    - Design an algorithm to serialize and deserialize a binary tree
        - Ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

    Time: O(N^2) [each node is visited once, memory copy using string concatenation], Space: O(N)
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string ans = "";
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    ans += to_string(root->val) + " ";

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
                ans += to_string(node->left->val) + " ";
            } else {
                ans += "null ";
            }
            if (node->right) {
                q.push(node->right);
                ans += to_string(node->right->val) + " ";
            } else {
                ans += "null ";
            }
        }
    }

    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data == "") return nullptr;

    stringstream ss(data);
    vector<string> nodes;
    string s;
    while (getline(ss, s, ' ')) {
        nodes.push_back(s);
    }

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    q.push(root);
    int index = 1;

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (index >= nodes.size()) {
                break;
            }
            if (nodes[index] != "null") {
                node->left = new TreeNode(stoi(nodes[index]));
                q.push(node->left);
            }
            index++;
            if (index >= nodes.size()) {
                break;
            }
            if (nodes[index] != "null") {
                node->right = new TreeNode(stoi(nodes[index]));
                q.push(node->right);
            }
            index++;
        }
    }

    return root;
}