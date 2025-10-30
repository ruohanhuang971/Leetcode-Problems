#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(1)
    Sometimes it is better to have 2 lists instead of 1
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    // edge case: empty/only one node
    if (!head || !head->next) {
        return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* temp = head;
    while (fast && fast->next) {
        temp = slow;
        fast = fast->next->next;  // 2 steps at a time
        slow = slow->next;        // 1 step at a time
    }

    temp->next = slow->next;
    delete slow;  // Free memory

    return head;
}