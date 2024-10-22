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

        if (head == nullptr || head->next == nullptr) return head;
        ListNode * temp = head->next;
        ListNode * sec =temp;
        ListNode * fir = head;
        while(head!=NULL && head->next!=NULL && temp->next!=NULL){
            
            head->next = temp->next;
            head = temp->next;
            temp->next = head->next;
            temp = head->next;

        }
        head->next = sec;
        return fir;
    }
};