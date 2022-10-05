/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseList(head: ListNode | null): ListNode | null {
    if(!head) return head;
    let myStack: ListNode[] = [];
    let cur: ListNode = head;
    
    while(cur) {
        myStack.push(cur);
        cur = cur.next;
    }
    
    let newHead: ListNode = myStack[myStack.length - 1];
    cur = newHead;
    myStack.pop();
        
    for(let i: number = myStack.length - 1; i>=0; i--) {
        cur.next = myStack[i];
        myStack.pop();
        cur = cur.next;
    }
    
    cur.next = null;
    
    return newHead;
};
