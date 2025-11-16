/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        

        ListNode * f = head;
        ListNode * s  = head;

        while(f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f){
                s=head;
                while(s){
                    if(s==f) return s;
                    s=s->next;
                    f=f->next;
        
                }
            }
        }
        return NULL;
    }

};