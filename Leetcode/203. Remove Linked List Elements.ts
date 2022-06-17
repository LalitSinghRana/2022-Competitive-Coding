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

function removeElements(head: ListNode | null, val: number): ListNode | null {
    while(head && head.val === val) head = head.next;
    if(!head) return head;
    
    let cur: ListNode = head.next, prev: ListNode = head;
    while(cur) {
        while(cur && cur.val === val) cur = cur.next;
        prev.next = cur;
        prev = cur;
        if(cur) cur = cur.next;
    }
    
    return head;
};
