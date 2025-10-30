#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    - Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
    - Determine if the input string is valid.
    Time: O(N), Space: O(N)
*/

/*
    Note:
    - for an opening bracket, push it to the top of the stack.
    - for closing bracket, check if the top of the stack was the opening for it. If yes, pop it from the stack. Otherwise, return false.
*/

bool isValid(string s) {
    stack<char> st;

    unordered_map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    for (auto n : s) {
        // n is open push to top of stack
        if (n == '(' || n == '{' || n == '[') {
            st.push(n);
            continue;
        }
        // if n is closing, check that top of stack have matching open
        if (st.empty()) return false;
        char top = st.top();
        st.pop();

        if (m[top] != n) return false;
    }

    return st.empty();
}