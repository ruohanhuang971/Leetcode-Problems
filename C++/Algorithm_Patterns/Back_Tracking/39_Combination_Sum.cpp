#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an array of distinct integers and a target
    - return a list of all unique combinations of candidates where the chosen numbers sum to target
        - may return the combinations in any order.
        - same number may be chosen unlimited number of times..
        - two combinations are unique if the frequency of at least one of the chosen numbers is different.

    Time: O(2^N) [worst case: explore all subsets of candidates]
    Space: O(t/d), where t is the target and d is the smallest candidate
*/

/*
    Intuition:
    - at each step, choose whether or no to pick current index
*/

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    helper(candidates, target, 0, 0, vector<int>(), ans);

    return ans;
}

void helper(vector<int>& candidates, int target, int index, int curSum, vector<int> curCombo, vector<vector<int>>& answer) {
    if (curSum == target) {
        answer.push_back(curCombo);
        return;
    }
    if (curSum > target) return;

    // don't include current index
    if (index < candidates.size()) {
        helper(candidates, target, index + 1, curSum, curCombo, answer);
        // include current index
        curCombo.push_back(candidates[index]);
        helper(candidates, target, index, curSum + candidates[index], curCombo, answer);
    }
}