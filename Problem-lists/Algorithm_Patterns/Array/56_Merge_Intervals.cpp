#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Given an array of intervals where intervals[i] = [starti, endi]
    Merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= ans[ans.size() - 1][1]) {
            ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
        } else {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}