class Solution {
public:
    bool dfs(int n , vector<vector<int>> & graph,vector<int>&color,int cc){

        color[n]=cc;
        for(auto i : graph[n]){

            if(color[i]==-1){
                if(!dfs(i,graph,color,1-cc)){
                    return false;
                }
            }
            else if(color[i]==cc) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v = graph.size();
        vector<int>color(v,-1);

        for(int i = 0 ; i < v ; i++){
            if(color[i]==-1){
                if(!dfs(i,graph,color,0)) return false;
            }
        }
    return true;
    }
};