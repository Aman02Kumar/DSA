class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        // Flatten left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Store the left and right subtree
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // Step 1: Move left subtree to right
        root->left = NULL;
        root->right = left;

        // Step 2: Go to end of new right subtree
        TreeNode* temp = root;
        while(temp->right){
            temp = temp->right;
        }

        // Step 3: Attach the original right subtree
        temp->right = right;
    }
};
