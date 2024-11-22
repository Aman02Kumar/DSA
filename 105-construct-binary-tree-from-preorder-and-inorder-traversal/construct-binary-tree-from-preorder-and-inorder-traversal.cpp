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
    int findpos(int ele ,vector<int>& inorder , int n ){
        for(int i = 0 ; i<n;i++){
            if(inorder[i] == ele){
                return i;
            }
            
        }
        return -1;
    }

    TreeNode* solve (vector<int>& preorder, vector<int>& inorder , int &index , int inorderstart , int inorderend , int n){

    if(index >= n || inorderstart > inorderend){
        return NULL;
    }        

    int ele = preorder[index++];
    TreeNode * root = new TreeNode(ele);
    int pos = findpos(ele , inorder , n);
    if (pos != -1) {
            root->left = solve(preorder, inorder, index, inorderstart, pos - 1, n);
            root->right = solve(preorder, inorder, index, pos + 1, inorderend, n);
        }

    return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

         int n = preorder.size();
         int preorderindex = 0 ;

        TreeNode * ans = solve(preorder , inorder,preorderindex, 0 , n-1 , n  );
        return ans;
        
    }
};