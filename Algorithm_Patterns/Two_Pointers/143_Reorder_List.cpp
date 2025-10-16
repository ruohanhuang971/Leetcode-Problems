#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
    - Given the head of a linked list
    - return if the linked list has a cycle in it.

    Time: O(N), Space: O(1)
*/

/*
    Intuition:
    - two approach:
        - just using the pointers:
            - each time find the end of the list and rearrange
        - use stack & fast/slow pointers:
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// stack & fast/slow pointers:
void reorderList(ListNode* head) {
    if (!head || !head->next)
        return;

    // try using a stack
    stack<ListNode*> s;

    // filling the stack with slow/fast pointer
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    while (slow) {
        s.push(slow);
        slow = slow->next;
    }

    // replace nodes with nodes popped from stack
    ListNode* node = head;
    while (!s.empty()) {
        ListNode* nextNode = s.top();
        s.pop();

        nextNode->next = node->next;
        node->next = nextNode;

        node = node->next->next;
    }
    node->next = nullptr;
}

// just using the pointers:
// Time: O(N^2), Space: O(1)
void reorderList(ListNode* head) {
    ListNode* start = head;

    while (start->next && start->next->next) {
        // find end
        ListNode* prev = start;
        ListNode* end = start->next;
        while (end->next) {
            prev = prev->next;
            end = end->next;
        }

        // cout << start->val << " " << end->val << endl;

        // (start) -> (end) -> (start->next) -> ... -> prev -> null
        end->next = start->next;
        start->next = end;
        prev->next = nullptr;

        // (done) -> (done) -> (start) -> ...
        start = start->next->next;
    }
}