#include <map>

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *temp = head;
        map<int, int> mp;

        while (temp != nullptr) {
            mp[temp->val]++;
            temp = temp->next;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
      
        for (auto x : mp) {
            if (x.second == 1) {
                ListNode *newNode = new ListNode(x.first);
                current->next = newNode;
                current = newNode;
            }
        }

        return dummy->next;
    }
};
