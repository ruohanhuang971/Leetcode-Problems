#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(N)
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

    // replace list with stack
    ListNode* cur_node = head;
    ListNode* to_replace = head->next;
    while (!s.empty()) {
        ListNode* next = s.top();
        s.pop();
        if (next == cur_node) break;

        cur_node->next = next;
        next->next = to_replace;

        cur_node = to_replace;
        to_replace = to_replace->next;
    }
    cur_node->next = nullptr;
}