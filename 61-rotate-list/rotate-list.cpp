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
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode * temp = head;
        if(head==NULL) return NULL;
        int c =0 ;
        while(temp->next!=NULL){
            
            temp = temp->next;
            c++;
           
        }

        temp->next = head;
        k = k %(c+1);
        int y = c - k;


        temp = head;
        while(y){
            temp  = temp->next;
            y--;
        }
        
        ListNode * rr = temp->next;
        temp->next =NULL;
        return rr;

    }
};