/*
    Prompt: There are n people that are split into some unknown number of groups.
    Each person is labeled with a unique ID from 0 to n - 1.

    You are given an integer array groupSizes, where groupSizes[i] is the size of the group that
    person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

    Return a list of groups such that each person i is in a group of size groupSizes[i].

    Each person should appear in exactly one group, and every person must be in a group.
    If there are multiple answers, return any of them. It is guaranteed that there will be at
    least one valid solution for the given input.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// idea: sort
vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    vector<vector<int>> ans;

    map<int, vector<int>> groups;
    for (int i = 0; i < groupSizes.size(); i++) {
        groups[groupSizes[i]].push_back(i);
    }

    for (auto i = groups.begin(); i != groups.end(); i++) {
        int curGroupSize = i->first;

        if (curGroupSize < i->second.size()) {
            int index = 0;
            while (index < i->second.size()) {
                vector<int> curGroup;
                while (curGroup.size() < i->first) {
                    curGroup.push_back(i->second[index]);
                    index++;
                }
                ans.push_back(curGroup);
            }
        } else {
            ans.push_back(i->second);
        }
    }

    return ans;
}

void printArray(vector<vector<int>> nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<int> groupSizes = {3,3,3,3,3,1,3};
    vector<vector<int>> ans = groupThePeople(groupSizes);
    printArray(ans);
}