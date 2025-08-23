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
    TreeNode* build(vector<int> nums, int start , int end){
        if(start> end)return NULL;
       
        int maxindex = start ;
        for(int i = start +1 ; i <= end ; i++){
            if(nums[i] > nums[maxindex])
                 maxindex = i;
        }
        TreeNode * maxx = new TreeNode(nums[maxindex]);

        maxx->left = build(nums,start,maxindex-1);
        maxx->right = build(nums, maxindex+1 , end);
        return  maxx;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // if(nums) return NULL;
        TreeNode* root = build(nums,0,nums.size()-1);
        return root;
    }
};