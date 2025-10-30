#include <iostream>
#include <vector>
using namespace std;

// Time: O(N), Space: O(N)

string removeStars(string s) {
    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '*') {
            ans.push_back(s[i]);
        } else {
            ans.pop_back();
        }
    }

    return ans;
}