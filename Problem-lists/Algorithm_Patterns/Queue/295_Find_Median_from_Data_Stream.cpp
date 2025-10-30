#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
    - Implement the MedianFinder class:
        - void addNum(int num): adds the integer num from the data stream to the data structure.
        - double findMedian(): returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

    Time:
        - Add: O(log n) [push/poping from heap]
        - Median: O(1) [.top()]
    Space: O(n) [store all elements in heap]
*/

/*
    Intuition:
    - keep a min-heap and max-heap to keep track of the left and right side of the data
    - this removes the need to sort the data everytime
*/

class MedianFinder {
   public:
    MedianFinder() {
    }

    void addNum(int num) {
        // check if left empty to place first element
        // check if new num is left than largest of left side
        if (left.empty() || num < left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // balance heaps so they are same size
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        // if odd number of elements
        if (left.size() > right.size()) {
            return left.top();
        }
        return ((double)left.top() + (double)right.top()) / 2;
    }

    // max heap for left side
    priority_queue<int> left;
    // min heap for right side
    priority_queue<int, vector<int>, greater<int>> right;
};