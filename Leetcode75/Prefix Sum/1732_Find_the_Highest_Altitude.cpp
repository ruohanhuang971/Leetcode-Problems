#include <iostream>
#include <vector>
using namespace std;

/*
    This is pretty easy in general
*/

int largestAltitude(vector<int>& gain) {
    int curHeight = 0;
    int maxHeight = 0;

    for (int i = 0; i < gain.size(); i++) {
        curHeight += gain[i];
        maxHeight = max(curHeight, maxHeight);
    }

    return maxHeight;
}