#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an array of intervals
    - Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
    Time: O(M * N), Space: O(M + N) [replaceRow at most M entries, replaceCol at most N entries]
*/

/*
    Note:
        - sort by end time
        - iterate through and if an interval overlaps with the previous one:
            - remove the one with the later end time ensures you keep as much room as possible for future intervals.
*/

static bool sortVec(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), sortVec);

    int endTime = INT_MIN;
    int remove = 0;
    for (auto i : intervals) {
        // if start is before end
        if (i[0] < endTime) {
            // remove the one with later end time
            remove++;
        } else {
            endTime = i[1];
        }
    }

    return remove;
}