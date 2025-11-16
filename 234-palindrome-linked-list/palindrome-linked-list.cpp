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
        
        ListNode* f = head;
        ListNode* s = head;

        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }

        ListNode* prev = NULL;
        ListNode* forw = NULL;
        ListNode* curr = s;
        while(curr){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        ListNode* x = head;
        ListNode* y = prev;
        while(y){
            if(x->val != y->val)return false;
            x=x->next;
            y = y ->next;
        }
        return true;
        
    }
};