#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    - Given an array of meeting time intervals intervals where intervals[i] = [start_i, end_i]
    - return the minimum number of conference rooms required.
        - Note: can attend a meeting if it's starting time is same as the previous meeting's ending time.

    Time: O(N logN) [sort], Space: O(N) [O(2n) for both arrays]
*/

/*
    Intuition:
    - line sweep algorithm:
        - a set of events in sorted order
        - at start, +1, at end, -1
        - return the largest number
*/

int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> starts, ends;

    // get vector of start and end times
    for (auto& interval : intervals) {
        starts.push_back(interval[0]);
        ends.push_back(interval[1]);
    }

    // Sort both arrays
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int rooms = 0;
    int maxRooms = 0;
    int startPtr = 0;
    int endPtr = 0;

    while (startPtr < intervals.size()) {
        if (starts[startPtr] < ends[endPtr]) {
            rooms++;
            maxRooms = max(maxRooms, rooms);
            startPtr++;
        } else {
            rooms--;
            endPtr++;
        }
    }

    return maxRooms;
}

int main() {
    // vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    vector<vector<int>> intervals = {{7, 10}, {2, 4}};
    int ret = minMeetingRooms(intervals);
    cout << "RETURN: " << ret << endl;

    return 0;
}