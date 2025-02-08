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
    int solve(TreeNode * root, bool &valid){

        if(root==NULL) return 0;

        int lh = solve(root->left,valid);
        int rh = solve(root->right,valid);

        if(abs(lh-rh) >1) valid = false;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        
        bool valid = true ;
        solve(root,valid);
        return valid;

    }
};