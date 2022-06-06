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

function getIntersectionNode(headA: ListNode | null, headB: ListNode | null): ListNode | null {
    let A = [], B = [];
    let cur = headA;
    while(cur) {
        A.push(cur);
        cur = cur.next;
    }
    
    cur = headB;
    while(cur) {
        B.push(cur);
        cur = cur.next;
    }
    
    A.reverse();
    B.reverse();
    
    let n = Math.min(A.length, B.length)
    let ans = null;
    
    for(let i=0; i<n; i++) {
        if(A[i] === B[i]) ans = A[i];
    }
    
    return ans;
};
