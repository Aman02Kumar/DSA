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
    ListNode* removeElements(ListNode* head, int x) {
        
        ListNode * dum = new ListNode(-1);
        dum->next = head;
        ListNode * cur = dum;

        while(cur && cur->next){
            if(cur->next->val == x){
                ListNode * temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else cur = cur->next;
        }
        return dum->next;
    }
};