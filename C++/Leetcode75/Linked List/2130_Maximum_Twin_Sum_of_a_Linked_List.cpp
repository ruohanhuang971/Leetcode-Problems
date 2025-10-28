#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(1)
    Use "slow and fast" method to find midpoint
    Reverse list at midpoint
    traverse the first half of list and reversed second half of list at the same time -> get sum
    save the max sum and return
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int pairSum(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next->next;
    }

    int max_sum = INT_MIN;
    ListNode* reversed = reverseList(slow);
    ListNode* cur = head;
    while (reversed) {
        int cur_sum = (cur->val + reversed->val);
        max_sum = max(cur_sum, max_sum);

        cur = cur->next;
        reversed = reversed->next;
    }

    return max_sum;
}

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* front = head;
    ListNode* end = head;
    ListNode* nextNode = head->next;

    while (nextNode) {
        ListNode* temp = nextNode->next;
        nextNode->next = front;
        end->next = temp;

        front = nextNode;
        nextNode = end->next;
    }

    return front;
}