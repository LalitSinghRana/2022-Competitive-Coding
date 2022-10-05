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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *first = head->next, *o = head, *e = head->next, *last = nullptr;
        
        while(o && e) {
            o->next = o->next->next;
            if(e->next) e->next = e->next->next;
            last = o;
            o = o->next;
            e = e->next;
        }
        if(o) last = o;
        last->next = first;
        
        return head;
    }
};
