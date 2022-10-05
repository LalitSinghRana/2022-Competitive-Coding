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
