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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = l1->val, b = l2->val, c = 0;
        int y = (a+b+c)%10;
        c = (a+b+c)/10;
        auto head = new ListNode(y);
        l1 = l1->next;
        l2 = l2->next;
        
        auto cur = head;
        
        while(l1 || l2) {
            a = 0;
            b = 0;
            if(l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if(l2) {
                b = l2->val;
                l2 = l2->next;
            }
            
            y = (a+b+c)%10;
            c = (a+b+c)/10;
            cur->next = new ListNode(y);
            cur = cur->next;
        }
        
        if(c) cur->next = new ListNode(c);
        
        return head;
    }
};
