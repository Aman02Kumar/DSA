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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* h = headA;
        ListNode* j = headB;
        while (h != j) {
            h = h == NULL ? headB : h->next;
            j = j == NULL ? headA : j->next;
        }
        return h;
    }
};