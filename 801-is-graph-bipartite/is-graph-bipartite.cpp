class Solution {
public:

    bool dfs(int c, int i , vector<int>&vis , vector<vector<int>> & graph){

        vis[i] = c;
        for(auto it : graph[i]){
            if(vis[it] == vis[i]){
                return false;
            }
            else if(vis[it] == -1){
                if(!dfs(1-c,it,vis,graph)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v = graph.size();
        vector<int>vis(v,-1);

        for(int i = 0 ; i <  v ; i++){

            if(vis[i]==-1 && !dfs(0,i,vis,graph)){
                return false;
            }
        }
        return true;

                
    }
};