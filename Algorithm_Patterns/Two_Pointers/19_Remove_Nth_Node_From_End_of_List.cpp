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
    - Two options:
        - One pass:
            - keep dummy pointing to head for cases that removes the head
            - keep fast & slow pointers that are n nodes apart
            - keep moving the pointers until fast pointer is at the end, then slow pointer is n from the end
        - Two pass:
            - pass 1: count how many nodes there are
            - pass 2: keep track of curNode and prevNode
                - when curNode is at numNode - n, replace curNode with curNode->next
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// One pass:
// Time: O(N), Space: O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // space out pointers
    for (int i = 0; i < n + 1; i++) {
        fast = fast->next;
    }

    // move pointers until fast is at end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // remove node
    slow->next = slow->next->next;

    return dummy->next;
}

// Two pass:
// Time: O(N), Space: O(1)
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