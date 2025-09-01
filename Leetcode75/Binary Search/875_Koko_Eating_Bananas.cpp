#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N * log(max_pile)), Space: O(1)
*/

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int ans = right;

    while (left <= right) {
        int mid = (right - left) / 2 + left;

        long long hoursNeeded = 0;
        for (auto n : piles) {
            hoursNeeded += eatBanana(n, mid);
            if (hoursNeeded > h) {
                break;  // No need to continue calculating
            }
        }

        if (hoursNeeded <= h) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

long long eatBanana(long long banana, int k) {
    return (banana + k - 1) / k;
}