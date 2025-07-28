#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int curwrite = 0;
    int i = 0;
    while (i < chars.size()) {
        int groupLength = 1;
        while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
            groupLength++;
        }
        chars[curwrite++] = chars[i];
        if (groupLength > 1) {
            for (char c : to_string(groupLength)) {
                chars[curwrite++] = c;
            }
        }
        i += groupLength;
    }
    return curwrite;
}