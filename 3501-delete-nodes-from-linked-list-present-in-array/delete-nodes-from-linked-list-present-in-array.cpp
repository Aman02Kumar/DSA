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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> st(nums.begin(), nums.end());

        // Step 1: remove leading nodes
        while (head && st.count(head->val)) {
            head = head->next;
        }

        // If list becomes empty
        if (!head) return nullptr;

        // Step 2: remove internal nodes
        ListNode* cur = head;
        while (cur && cur->next) {
            if (st.count(cur->next->val)) {
                cur->next = cur->next->next; // skip node, no delete
            } else {
                cur = cur->next;
            }
        }

        return head;
    }
};
