#include <iostream>
#include <vector>
using namespace std;

/*
    Time: O(N), Space: O(1)
    Pointers for the front of the new array and the end
    front keep track of where the next one to process is
    end keep track where to add the next
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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