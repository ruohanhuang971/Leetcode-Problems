#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    helper(k, n, 1, vector<int>(), ans);

    return ans;
}

void helper(int k, int target, int start, vector<int> curCombo, vector<vector<int>>& ans) {
    if (target == 0 && k == 0) {  // reached number limit
        ans.push_back(curCombo);
        return;
    }

    for (int i = start; i <= 9; ++i) {
        if (i > target || k <= 0) break;
        curCombo.push_back(i);
        helper(k - 1, target - i, i + 1, curCombo, ans);
        curCombo.pop_back();
    }

    return;
}