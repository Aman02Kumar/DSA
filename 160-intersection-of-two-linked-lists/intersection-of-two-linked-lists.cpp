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
    ListNode *getIntersectionNode(ListNode *h ,ListNode *k) {
        
        while(h !=NULL){
            ListNode * j = k;
            while(j!=NULL){
                if(h == j ) return h;
                j = j->next;
            }
            h = h->next;
        }
        return NULL;
    }
};