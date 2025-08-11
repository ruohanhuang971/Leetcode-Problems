#include <iostream>
#include <queue>
using namespace std;

/*
    Remember Queue is FIFO
*/

class RecentCounter {
   public:
    RecentCounter() {
    }

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }

    queue<int> q;
};