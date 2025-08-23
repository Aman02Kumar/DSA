class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;

        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);

            // Pop smaller elements → they become left child
            while (!st.empty() && st.top()->val < num) {
                curr->left = st.top();
                st.pop();
            }

            // After popping, if stack still has bigger parent
            if (!st.empty()) {
                st.top()->right = curr;
            }

            st.push(curr);
        }

        // The root is at the bottom of stack
        while (st.size() > 1) {
            st.pop();
        }
        return st.top();
    }
};
