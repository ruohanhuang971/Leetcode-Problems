#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(1)
    Intuition: slow/fast pointers
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