#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N^2), Space: O(N)
*/

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> province(n, -1);

    for (int i = 0; i < n; i++) {
        findCircle(isConnected, i, province, i);
    }

    sort(province.begin(), province.end());
    int prev = province[0];
    int ans = 1;
    for (int i = 0; i < province.size(); i++) {
        if (province[i] != prev) {
            ans++;
            prev = province[i];
        }
    }

    return ans;
}

void findCircle(vector<vector<int>>& isConnected, int city, vector<int>& province, int group) {
    if (province[city] != -1) {
        return;
    }

    province[city] = group;
    for (int i = 0; i < isConnected[city].size(); i++) {
        if (isConnected[city][i] == 1) {
            findCircle(isConnected, i, province, group);
        }
    }

    return;
}