# **List Node**

**define a node**
```js
class ListNode {
  constructor(val, next = null) {
    this.val = val;
    this.next = next;
  }
}
```

**insert at beginning**
```js
const newNode = new ListNode(0);
newNode.next = head;
head = newNode; // head → 0 -> 1 -> 2 -> 3
```
