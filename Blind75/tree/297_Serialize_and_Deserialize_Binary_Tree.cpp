#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    ans += to_string(node->val) + " ";

                    q.push(node->left);
                    q.push(node->right);

                } else {
                    ans += "null ";
                }
            }
        }

        // cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;

        // parse string
        stringstream ss(data);
        string str;
        vector<string> treeData;
        while (getline(ss, str, ' ')) {
            treeData.push_back(str);
        }

        // root
        int index = 0;
        TreeNode* root = new TreeNode(stoi(treeData[index]));
        index++;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();

            // cout << node->val << " " << index<< endl;

            q.pop();

            if (index > treeData.size()) break;
            if (treeData[index] != "null") {
                node->left = new TreeNode(stoi(treeData[index]));
                q.push(node->left);
            }
            index++;
            if (index > treeData.size()) break;
            if (treeData[index] != "null") {
                node->right = new TreeNode(stoi(treeData[index]));
                q.push(node->right);
            }
            index++;
        }

        return root;
    }
};