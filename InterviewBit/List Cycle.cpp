/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *s=A, *f=A;
    while(f && f->next) {
        s = s->next;
        f = f->next->next;
        if(s == f) break;
    }

    if(f==NULL || f->next==NULL) return NULL;

    s=A;
    while(s!=f) {
        s = s->next;
        f = f->next;
    }

    return s;
}
