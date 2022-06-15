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

function deleteDuplicates(head: ListNode | null): ListNode | null {
    if(!head) return head;
    let prev: ListNode = head, cur: ListNode = head.next;
    
    while(cur) {
        if(cur.val != prev.val) {
            prev.next = cur;
            prev = cur;
        }
        cur = cur.next;
    }
    prev.next = null;
    
    return head;
};
