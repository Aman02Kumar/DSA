class Solution {
public:
    void dfs(int node , vector<int> &vis,vector<vector<int>>& adj){

        vis[node]=1;
        int s  = adj.size();
        for(int i = 0; i <s ; i++){
            if(vis[i]==0 && adj[node][i]==1){
                dfs(i,vis,adj);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        int cnt = 0 ;

        for(int i  = 0; i<n; i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};