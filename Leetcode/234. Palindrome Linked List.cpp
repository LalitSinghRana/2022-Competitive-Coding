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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        ListNode *h = new ListNode(head->val);
        ListNode *t = h, *cur = head->next;
        
        while(cur) {
            t->next = new ListNode(cur->val);
            cur = cur->next;
            t = t->next;
        }
        
        
        ListNode *rev = reverseList(h);
        
        ListNode *rcur = rev;
        cur = head;
        
        while(cur) {
            if(cur->val != rcur->val) return false;
            cur = cur->next;
            rcur = rcur->next;
        }
        
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        stack<ListNode*> s;
        ListNode *cur = head;
        
        while(cur) {
            s.push(cur);
            cur = cur->next;
        }
        
        ListNode *newHead = s.top();
        s.pop();
        cur = newHead;
        
        while(!s.empty()) {
            cur->next = s.top();
            s.pop();
            cur = cur->next;
        }
        cur->next = nullptr;
        
        return newHead;
    }
};
