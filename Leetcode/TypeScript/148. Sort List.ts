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

function sortList(head: ListNode | null): ListNode | null {
    let v = [];
    
    let cur = head;
    while(cur) {
        v.push(cur.val);
        cur = cur.next;
    }
    
    v.sort((a,b) => a-b);
    
    cur = head;
    for(let i=0; i<v.length; i++) {
        cur.val = v[i];
        cur = cur.next;
    }
    
    return head;
};
