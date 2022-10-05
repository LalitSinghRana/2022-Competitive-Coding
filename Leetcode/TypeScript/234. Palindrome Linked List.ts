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

function isPalindrome(head: ListNode | null): boolean {
    let arr: number[] = [];
    let cur: ListNode = head;
    while(cur) {
        arr.push(cur.val);
        cur = cur.next;
    }
    
    for(let i=0; i<Math.floor(arr.length/2); i++) {
        if(arr[i] !== arr[arr.length-1-i]) return false;
    }
    
    return true;
};
