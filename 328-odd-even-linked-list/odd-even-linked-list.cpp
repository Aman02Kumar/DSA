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
        ListNode* od = head;
        ListNode* ev = head->next;
        ListNode* ehed = ev;

        while(ev && ev->next){
            od->next = ev->next;
            od = od->next;

            ev->next = od->next;
            ev = ev->next;
        }
        od->next = ehed;
        return head;

    }
};