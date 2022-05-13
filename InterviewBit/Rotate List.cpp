/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode *i=A;
    int n=0;
    while(i) {
        n++;
        i = i->next;
    }

    int k=n-(B%n);
    if(k==0 || k==n) return A;
    i=A;
    while(--k > 0) i = i->next;
    
    ListNode *head = i->next;
    i->next = NULL;
    i=head;
    while(i->next) i = i->next;
    i->next = A;

    return head;
}
