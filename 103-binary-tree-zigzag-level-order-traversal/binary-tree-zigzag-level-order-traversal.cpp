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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        stack<TreeNode*> q1;
        stack<TreeNode *> q2;

        q1.push(root);
        while(!q1.empty() || !q2.empty()){
            vector<int> k;
           
            while(!q1.empty()){
                    TreeNode * x = q1.top();
                    q1.pop();
                    k.push_back(x->val); 
                    if(x->left) q2.push(x->left);
                    if(x->right) q2.push(x->right);
                    
            }
            
            if(!k.empty()) ans.push_back(k);
            k.clear(); 

            while(!q2.empty()){
                    TreeNode* x = q2.top();
                    q2.pop();
                    k.push_back(x->val); 
                    if(x->right) q1.push(x->right);
                    if(x->left) q1.push(x->left);
                    
                }
            
            if(!k.empty()) ans.push_back(k);

        }
        return ans;
    }
};