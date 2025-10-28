#include <iostream>
#include <vector>
using namespace std;

// Time: O(N), Space: I(N)

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    for (int i = 0; i < asteroids.size(); i++) {
        bool add = true;
        while (!ans.empty()) {
            int prev = ans.back();
            int cur = asteroids[i];
            // -> -> || <- <- || <- ->
            if (prev > 0 && cur > 0 || prev < 0 && cur < 0 ||
                prev < 0 && cur > 0) {
                ans.push_back(cur);
                break;
            }
            if (abs(prev) > abs(cur)) {
                add = false;
                break;
            } else if (abs(prev) == abs(cur)) {
                add = false;
                ans.pop_back();
                break;
            } else {
                ans.pop_back();
            }
        }
        if (ans.empty() && add) {
            ans.push_back(asteroids[i]);
        }
    }

    return ans;
}