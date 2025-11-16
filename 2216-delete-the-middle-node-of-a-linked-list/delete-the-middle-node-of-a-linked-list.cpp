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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
         ListNode* d = NULL;
          ListNode* s = head;
           ListNode* f = head;

           while(f && f->next){
            d = s;
            s = s->next;
            f = f->next->next;
           }

           d->next = s ->next;
           delete s;
return head;
    }
};