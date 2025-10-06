#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
    Optimal solution: Divide & Conquer
    Time: O(Nlogk), Space: O(logk)
*/
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    return helper(lists, 0, lists.size() - 1);
}

ListNode* helper(vector<ListNode*>& lists, int left, int right) {
    if (left == right) return lists[left];

    int mid = left + (right - left) / 2;
    ListNode* list1 = helper(lists, left, mid);
    ListNode* list2 = helper(lists, mid + 1, right);
    return mergeTwoLists(list1, list2);
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

/*
    Solution I tried: Not optional
    Time: O(NlogN), Space: O(N)
*/
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;

    // idea 1: use a map that map node->val to node
    map<int, vector<ListNode*>> m;
    for (auto n : lists) {
        while (n) {
            m[n->val].push_back(n);
            n = n->next;
        }
    }

    ListNode* head = nullptr;
    ListNode* ans = new ListNode();
    for (auto n = m.begin(); n != m.end(); n++) {
        vector<ListNode*> temp = n->second;
        for (auto n : temp) {
            ans->next = n;
            ans = ans->next;
            if (!head) head = ans;
        }
    }

    return head;
}