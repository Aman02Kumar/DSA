/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> st;
        vector<double> ans;

        st.push(root);

        while(!st.empty()){
           
            double value =0;
            double count = 0;

            int n = st.size();
            while(n--){
                TreeNode* node = st.front();
                st.pop();

                if(node->left) st.push(node->left);
                if(node->right) st.push(node->right);

                value+=node->val;
                count++;
            }
            ans.push_back((double)value/count);
        }
        return ans;
    }
};