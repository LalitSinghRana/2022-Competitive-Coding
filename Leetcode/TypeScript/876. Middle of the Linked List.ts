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

function middleNode(head: ListNode | null): ListNode | null {
    let cnt: number = 0;
    let cur: ListNode = head;
    while(cur) {
        cnt++;
        cur = cur.next;
    }
    
    cnt = Math.floor(cnt/2) + 1;
    cur = head;
    
    while(--cnt) {
        cur = cur.next;
    }
    
    return cur;
};
