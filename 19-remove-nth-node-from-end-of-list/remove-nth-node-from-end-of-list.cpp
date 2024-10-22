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
        ListNode * temp = head;
        if(head==NULL || head->next ==NULL) return NULL;
        int c = 0;
        while(temp!=NULL){
            temp = temp->next;
            c++;
        }
    
        int x = c - n ;
        if(c==n) {
            // head = head->next;
            return head->next;
        }

        temp = head;
        while(x-1>0){
            temp = temp->next;
            x--;
        }
        temp ->next = temp->next->next;
        return head;

    }
};
