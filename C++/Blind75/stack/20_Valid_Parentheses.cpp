#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
*/

bool isValid(string s) {
    int n = s.size();
    stack<char> st;

    std::map<char, char> m = {{')', '('}, {'}', '{'}, {']', '['}};
    for (auto c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
            continue;
        }
        char lookFor = m[c];
        if (st.empty()) return false;
        char top = st.top();
        st.pop();

        // cout << c << " " << lookFor << " " << top << endl;

        if (top != lookFor) return false;
    }

    return st.empty();
}