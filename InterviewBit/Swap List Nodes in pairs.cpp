/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *i=A, *j=A->next;
    while(j != NULL) {
        swap(i->val, j->val);
        i = i->next->next;
        j = j->next;
        if(j != NULL) j = j->next;
    }
    return A;
}
