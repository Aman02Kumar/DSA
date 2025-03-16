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
    bool isCousins(TreeNode* root, int x, int y) {
    if (!root) return false;

    queue<pair<TreeNode*, TreeNode*>> q; // Pair of (node, parent)
    q.push({root, nullptr});

    while (!q.empty()) {
        int size = q.size();
        TreeNode* parentX = nullptr;
        TreeNode* parentY = nullptr;

        // Process all nodes at the current level
        for (int i = 0; i < size; i++) {
            pair<TreeNode*, TreeNode*> frontPair = q.front();
            TreeNode* node = frontPair.first;
            TreeNode* parent = frontPair.second;
            q.pop();

            // Check if the current node is x or y
            if (node->val == x) parentX = parent;
            if (node->val == y) parentY = parent;

            // Push child nodes into the queue
            if (node->left) q.push({node->left, node});
            if (node->right) q.push({node->right, node});
        }

        // If both nodes are found at the same level and have different parents
        if (parentX && parentY) return parentX != parentY;

        // If only one node is found at this level, they are not cousins
        if (parentX || parentY) return false;
    }

    return false;
}
};