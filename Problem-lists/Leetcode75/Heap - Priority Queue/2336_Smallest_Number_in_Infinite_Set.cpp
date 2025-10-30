#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

/*
    Time complexity:O(logN), Space complexity:O(N)
*/

class SmallestInfiniteSet {
   public:
    SmallestInfiniteSet() {
    }

    int popSmallest() {
        int ans;
        if (s.empty()) {
            ans = cur;
            cur++;
        } else {
            int smallest = *s.begin();
            s.erase(s.begin());
            return smallest;
        }
        return ans;
    }

    void addBack(int num) {
        if (num < cur) {
            s.insert(num);
        }
    }

    std::set<int> s;
    int cur = 1;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */