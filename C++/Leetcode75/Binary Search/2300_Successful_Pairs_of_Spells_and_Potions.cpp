#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(NlogN + NlogM), Space: O(N)
*/

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                            long long success) {
    sort(potions.begin(), potions.end());
    int n = spells.size();
    int m = potions.size();

    vector<int> ans(n);
    int left;
    int right;
    int mid;
    for (int i = 0; i < n; i++) {
        left = 0;
        right = m - 1;

        while (left <= right) {
            mid = (right - left) / 2 + left;
            if ((long long int)potions[mid] * (long long int)spells[i] >= success) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        ans[i] = m - right - 1;
    }

    return ans;
}