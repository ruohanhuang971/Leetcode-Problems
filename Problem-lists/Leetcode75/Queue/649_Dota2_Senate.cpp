#include <iostream>
#include <queue>
using namespace std;

/*
    Time: O(N), Space: O(N)
*/

string predictPartyVictory(string senate) {
    queue<int> radiant;
    queue<int> dire;
    for (int i = 0; i < senate.size(); i++) {
        if (senate[i] == 'R') {
            radiant.push(i);
        } else {
            dire.push(i);
        }
    }

    int index = senate.size();
    while (!radiant.empty() && !dire.empty()) {
        index++;
        if (radiant.front() < dire.front()) {
            radiant.push(index);
        } else {
            dire.push(index);
        }
        radiant.pop(), dire.pop();
    }

    if (radiant.empty()) {
        return "Dire";
    } else {
        return "Radiant";
    }
}