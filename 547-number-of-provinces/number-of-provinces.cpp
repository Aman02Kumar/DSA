class Solution {
public:
    
    void dfs(int node , vector<int>&v,vector<int> adj[]){
        v[node]=1;
        for(auto i : adj[node]){
            if(!v[i]){
            dfs(i,v,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        

        int n = isConnected.size();
        vector<int> adj[n];

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> v(n,0);
        int cnt = 0 ;
        for(int i = 0 ; i<n;i++){

                if(!v[i]){
                    cnt++;
                    dfs(i,v,adj);
                }
        }
        return cnt;
    }
};