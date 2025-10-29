/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
    let dummy = new ListNode(0, head);

    let temp = dummy;
    for (let i = 0; i < n - 1; i++) {
        temp = temp.next;
    }

    let x = dummy;
    while (temp.next && temp.next.next) {
        temp = temp.next;
        x = x.next;
    }
    x.next = x.next.next;

    return dummy.next;
};