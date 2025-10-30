#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    Time complexity:O(N), Space complexity:O(N)
*/

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (auto u : nums) {
        pq.push(u);  // put everything into priority_queue
    }
    int val;
    while (k--) {
        val = pq.top();  // get largest element
        pq.pop();
    }
    return val;
}