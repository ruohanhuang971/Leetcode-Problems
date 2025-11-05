#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    - Given two integers a and b
    - Return the sum of the two integers without using the operators + and -.
*/

/*
    Intuition:
    - XOR does add without handling the carry
        - 10 ^ 01 = 11, 2 + 1 = 3
    - AND handles the carry and left shift so its at the right position
        - 11 & 10 = 10, 10 << 1 = 100
*/

int getSum(int a, int b) {
    int c;
    while (b != 0) {
        c = (a & b);   // AND a and b for carry
        a = a ^ b;     // XOR a and b for addition without carry
        b = (c) << 1;  // shift over carry by 1 for more operations
    }
    return a;
}