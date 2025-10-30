#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    vector<char> temp;
    int count = 1;

    for (int i = 1; i <= chars.size(); i++) {
        if (i < chars.size() && chars[i] == chars[i - 1]) {
            count++;
        } else {
            temp.push_back(chars[i - 1]);
            if (count > 1) {
                for (char x : to_string(count)) {
                    temp.push_back(x);
                }
            }
            count = 1;
        }
    }

    chars = temp;
    return chars.size();
}