ListNode* Solution::solve(ListNode* A) {
    int cnt=0;
    ListNode* cur = A;
    while(cur != NULL) {
        if(cur->val == 0) cnt++;
        cur = cur->next;
    }

    cur = A;
    while(cur != NULL) {
        if(cnt>0) {
            cur->val = 0;
            cnt--;
        } else cur->val = 1;
        cur = cur->next;
    }

    return A;
}
