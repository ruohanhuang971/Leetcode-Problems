#include <iostream>
#include <vector>
using namespace std;

/*
    - Given the head of a linked list
    - return if the linked list has a cycle in it.

    Time: O(N), Space: O(1)
*/

/*
    Intuition:
    - classic cycle detection -> use same fast/slow pointer
    - if fast pointer ever lap slow pointer -> cycle
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    // slow/fast pointer
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}