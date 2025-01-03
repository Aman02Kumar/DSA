class BSTIterator {
private: stack<TreeNode*>myStack;
    void pushAll(TreeNode* node){
        while(node != NULL){
             myStack.push(node);
             node=node->left;
    }
    }

public:
    
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};