/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *i = A, *j = A->next;

    while(j != NULL) {
        if(i->val != j->val) {
            i->next = j;
            i = j;
        }
        j = j->next;
    }
    i->next = NULL;
    return A;
}
