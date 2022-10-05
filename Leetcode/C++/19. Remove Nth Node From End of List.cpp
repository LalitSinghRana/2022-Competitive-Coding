/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;
        ListNode *cur = head, *prev = nullptr, *ans = head;
        while(cur) {
            m++;
            cur = cur->next;
        }
        
        int k = m - n + 1;
        cur = head;
        while(k) {
            if(k == 1) {
                if(!prev) {
                    ans = cur->next;
                    cur->next = nullptr;
                } else {
                    prev->next = cur->next;
                    cur->next = nullptr;
                }
                break;
            }
            prev = cur;
            cur = cur->next;
            k--;
        }
        
        return ans;
    }
};
