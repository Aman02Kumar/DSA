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
    
    int  height(TreeNode * root,bool & s){
        if(root == NULL) return 0;
        int l  = height(root->left,s);
        int r  = height(root->right,s);

        if(abs(l-r) > 1) s = false;

        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool s = true;
        height(root,s);
        return s;
    }
};