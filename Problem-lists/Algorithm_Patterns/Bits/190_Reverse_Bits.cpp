#include <iostream>
#include <vector>
using namespace std;

/*
    - Reverse bits of a given 32 bits signed integer.

    Time: O(1), Space complexity: O(1)
*/

/*
    Intuition: Divide and Conquer
        12345678 --> original number
        5678|1234
        78|56 34|12
        8|7 6|5 4|3 2|1 --> desired number(reversed number)
*/

int reverseBits(int n) {
    // divide and conquer
    n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
    n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
    n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
    n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);

    return n;
}