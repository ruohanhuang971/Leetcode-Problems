#include <iostream>
#include <vector>
using namespace std;

/*
    - Given an integer array nums representing the amount of money of each house
    - Return the maximum amount of money you can rob tonight without alerting the police.

    Time: O(N), Space complexity: O(1)
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* cur = head;
    ListNode* next = head->next;

    while (next) {
        ListNode* temp = next->next;
        next->next = cur;
        cur = next;
        next = temp;
    }
    head->next = nullptr;

    return cur;
}