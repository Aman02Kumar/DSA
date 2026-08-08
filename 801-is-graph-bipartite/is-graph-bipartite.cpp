class Solution {
public:

    bool bfs(int i , vector<int>&vis , vector<vector<int>> & graph){

        queue<int> q;
        q.push(i);
        vis[i]=0;

        while(!q.empty()){

            int n = q.front();
            q.pop();

            for(auto it : graph[n]){
                if(vis[it] == -1 ){
                    vis[it] = 1 - vis[n];
                    q.push(it);
                }
                else if(vis[it] == vis[n]){
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

            if(vis[i]==-1 && !bfs(i,vis,graph)){
                return false;
            }
        }
        return true;

                
    }
};