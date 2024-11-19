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

    static bool myCmp(const pair<TreeNode*, pair<int, int>>& a, const pair<TreeNode*, pair<int, int>>& b){
        if(a.second.second!=b.second.second){
            return a.second.second<b.second.second;
        }
        if(a.second.first!=b.second.first){
            return a.second.first<b.second.first;
        }
        return a.first->val<b.first->val;
    }

    void inorderTraversal(TreeNode* node, vector<pair<TreeNode*, pair<int,int>>>& vec, int i, int j){
        if(node==NULL){
            return;
        }

        inorderTraversal(node->left,vec,i+1,j-1);
        vec.push_back({node,{i,j}});
        inorderTraversal(node->right, vec, i+1, j+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<TreeNode*, pair<int,int>>> vec;
        inorderTraversal(root,vec,0,0);
        sort(vec.begin(),vec.end(),myCmp);
        map<int,vector<int>> mpp;
        for(auto& it:vec){
            mpp[it.second.second].push_back(it.first->val);
        }

        vector<vector<int>> ans;
        for(auto& p: mpp){
            ans.push_back(p.second);
        }

        return ans;

    }
};