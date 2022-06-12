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

function mergeTwoLists(list1: ListNode | null, list2: ListNode | null): ListNode | null {
    if(list1 === null) return list2;
    if(list2 === null) return list1;
    
    let head: ListNode;
    
    if(list1.val <= list2.val) {
            head = list1;
            list1 = list1.next;
        } else {
            head = list2;
            list2 = list2.next;
        }
    
    let cur: ListNode = head;
    
    while(list1 !== null && list2 !== null) {
        if(list1.val <= list2.val) {
            cur.next = list1;
            cur = cur.next;
            list1 = list1.next;
        } else {
            cur.next = list2;
            cur = cur.next;
            list2 = list2.next;
        }
    }
    
    (list1 === null) ? cur.next = list2 : cur.next = list1;
    
    return head;
};
