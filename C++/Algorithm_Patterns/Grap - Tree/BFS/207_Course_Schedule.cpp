#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    - There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
    - given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take
      course bi first if you want to take course ai.
    - Return true if you can finish all courses. Otherwise, return false.

    Time: O(V + E), Space: O(V + E)
*/

/*
    Intuition:
    - Kahn’s Algorithm (topological sorting using BFS):
        - checks a directed graph and gives an order that: for every directed edge u → v, node u comes before node v in the ordering
        - if there is a cycles, the topological sorting order will be less than the # of nodes
*/

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // key[prerequisites course] : value [courses that depend on this course]
    unordered_map<int, vector<int>> m;
    // how many courses need this course
    vector<int> numDependent(numCourses, 0);
    for (auto n : prerequisites) {
        m[n[1]].push_back(n[0]);
        numDependent[n[0]]++;
    }

    // add courses with no prerequisites
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (numDependent[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        auto t = q.front();
        ans.push_back(t);
        q.pop();

        // check tasks without dependency after removing dependency of t
        for (auto x : m[t]) {
            numDependent[x]--;
            if (numDependent[x] == 0) {
                q.push(x);
            }
        }
    }

    return ans.size() == numCourses;
}