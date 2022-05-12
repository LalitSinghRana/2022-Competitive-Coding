/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode *cur = A;
    int n=0;
    while(cur != NULL) {
        n++;
        cur = cur->next;
    }

    int num = (n/2) + 1 - B;

    cur = A;
    while(num > 0) {
        num--;
        if(!num) return cur->val;
        cur = cur->next;
    }

    return -1;
}
