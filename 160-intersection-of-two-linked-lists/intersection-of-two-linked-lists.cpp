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
    ListNode *getIntersectionNode(ListNode *h1  ,ListNode *h2 ) {

            map<ListNode*,int> mp;
            while(h1!=NULL){
                mp[h1]++;
                h1=h1->next;
            }

            while(h2!=NULL){
                if(mp[h2] == 1) return h2;
                h2 = h2->next;
            }
            return NULL;
        
    }
};