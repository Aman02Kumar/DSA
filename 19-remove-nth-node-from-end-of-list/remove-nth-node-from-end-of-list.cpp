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

        if(head == NULL || head ->next==NULL) return NULL;
        ListNode * f = head;
        ListNode * s = head;
        while(n){
            f = f->next;
            n--;
        }
        if(f==NULL){return head->next;}

        while( f->next!=NULL){
            s = s->next;
            f= f->next;

        }

        s->next = s->next->next;
        return head;
    }
};