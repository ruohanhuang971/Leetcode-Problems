#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
    Time: O(N), Spac: O(N)
    Intuation: Start operation when hitting a ']' and stop when hitting '[' which guarrentee correct nesting
                Also it make sure the by the time it gets to the end, all the '[]' have been processed
*/

string decodeString(string s) {
    string encode;
    stack<int> freq;
    string cur_read;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= '9') {  // is number
            cur_read += s[i];
        } else if (s[i] == '[') {
            encode += s[i];
            freq.push(stoi(cur_read));
            cur_read = "";
        } else if (s[i] == ']') {
            string temp;
            while (encode.back() != '[') {
                temp += encode.back();
                encode.pop_back();
            }
            encode.pop_back();  // remove [
            int repeat = freq.top();
            freq.pop();

            string str = "";
            for (int i = temp.size() - 1; i >= 0; i--) {  // reverse order
                str += temp[i];
            }

            for (int i = 0; i < repeat; i++) {
                encode += str;
            }
        } else {
            encode += s[i];
        }
    }

    return encode;
}