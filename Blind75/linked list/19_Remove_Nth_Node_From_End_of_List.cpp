#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(1)
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return nullptr;

    int size = 0;
    ListNode* cur = head;
    while (cur) {
        cur = cur->next;
        size++;
    }

    cur = head;
    ListNode* prev = nullptr;
    for (int i = 0; i < size - n; i++) {
        prev = cur;
        cur = cur->next;
    }

    if (!prev) {  // remove first
        return cur->next;
    } else if (n == 1) {  // remove last
        prev->next = nullptr;
    } else {  // remove middle
        prev->next = cur->next;
    }

    return head;
}