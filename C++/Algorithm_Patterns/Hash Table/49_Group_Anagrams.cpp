#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    - Given an unsorted array of integers nums
    - Return the length of the longest consecutive elements sequence.
    Time: O(N * len(longestString)), Space: O(N * len(longestString))
*/

/*
    Note:
    - Just sort the words
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;

    for (int i = 0; i < strs.size(); i++) {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        m[temp].push_back(strs[i]);
    }

    vector<vector<string>> ans;
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        ans.push_back(itr->second);
    }

    return ans;
}