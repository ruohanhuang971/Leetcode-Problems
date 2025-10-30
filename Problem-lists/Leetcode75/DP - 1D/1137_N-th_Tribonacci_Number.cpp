#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(1)
*/

int tribonacci(int n) {
    int start = 0;
    int prev = 1;
    int cur = 1;

    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int sum = 0;
    int i = 3;
    while (i <= n) {
        sum = start + prev + cur;
        start = prev;
        prev = cur;
        cur = sum;
        i++;
    }
    return sum;
}