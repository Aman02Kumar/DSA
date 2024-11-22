/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode * root ,  map < TreeNode *  , TreeNode * > &track){

        queue< TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            TreeNode * n = q.front();
            q.pop();
            if(n->left){
                q.push(n->left);
                track[n->left] = n ;
            } 
            if(n->right){
                q.push(n->right);
                track[n->right] = n ;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map < TreeNode * , TreeNode * > track;
        parent(root,track);

        map<TreeNode * , bool > visit;
        queue < TreeNode * > qq;

        int level = 0 ;
        qq.push(target);
        visit[target] = 1;

        while(!qq.empty()){
        if(level == k ) break;
        level++;

        int s = qq.size();
        for(int  i= 0 ; i < s ;i++){
            
            TreeNode * nn = qq.front();
            qq.pop();
            if(nn->left && visit[nn->left] == 0){
                qq.push(nn->left);
                visit[nn->left] = 1;
            }
            if(nn->right && visit[nn->right] == 0){
                qq.push(nn->right);
                visit[nn->right] = 1;
            }
            if(track[nn] && visit[track[nn]] == 0 ){
                qq.push(track[nn]);
                visit[track[nn]] =1;
            }
        }

        }

        vector<int>ans;
        while(!qq.empty()){
            TreeNode * cur = qq.front();
            ans.push_back(cur->val);
            qq.pop();
        }
        return ans;
    }
};