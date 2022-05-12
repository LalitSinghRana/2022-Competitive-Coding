/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(A == NULL) return B;
    if(B == NULL) return A;
    int c = (A->val + B->val)/10;
    ListNode *head = new ListNode((A->val + B->val)%10);
    ListNode *cur = head, *i=A->next, *j=B->next;

    while(i !=NULL || j != NULL) {
        if(i == NULL) {
            cur->next = new ListNode((j->val + c)%10);
            c = (j->val + c)/10;
            cur = cur->next;
            j = j->next;
        } else if(j == NULL) {
            cur->next = new ListNode((i->val + c)%10);
            c = (i->val + c)/10;
            cur = cur->next;
            i = i->next;
        } else {
            cur->next = new ListNode((i->val + j->val + c)%10);
            c = (i->val + j->val + c)/10;
            cur = cur->next;
            i = i->next;
            j = j->next;
        }
    }

    if(c > 0) cur->next = new ListNode(c);
    return head;
}
