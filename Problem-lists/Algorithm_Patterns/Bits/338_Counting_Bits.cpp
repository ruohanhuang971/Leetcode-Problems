#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an integer n
    - Return an array ans of length n + 1, ans[i] is the number of 1's in the binary representation of i.

    Time: O(N), Space complexity: O(1)
*/

/*
    There are 2 cases:
    - even -> the number of 1 is the same as n / 2 -> just add an 0 for * 2
    - odd -> the number of 1 is (previous even #) + 1. since previous even # is n / 2, this simplify to (n / 2) + 1

    So for each number it is n / 2 + n % 2
*/

vector<int> countBits(int n) {
    // if odd => (previous even # of 1) + 1 => (n / 2) + 1
    // if even => (same as n / 2) -> just add an 0 for * 2
    vector<int> ans(n + 1);
    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i / 2] + i % 2;
    }

    return ans;
}