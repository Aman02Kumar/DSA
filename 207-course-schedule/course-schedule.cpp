class Solution {
public:

    bool dfs(int node,
             vector<int>& vis,
             vector<int>& path,
             vector<int> adj[],
             stack<int>& st) {

        vis[node] = 1;
        path[node] = 1;

        for(auto neighbour : adj[node]) {

            if(!vis[neighbour]) {

                if(dfs(neighbour, vis, path, adj, st))
                    return true;
            }
            else if(path[neighbour]) {

                return true;
            }
        }

        path[node] = 0;

        st.push(node);

        return false;
    }

    bool canFinish(int v, vector<vector<int>>& pre) {

        vector<int> adj[v];

        for(auto edge : pre) {

            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(v, 0);
        vector<int> path(v, 0);

        stack<int> st;

        for(int i = 0; i < v; i++) {

            if(!vis[i]) {

                if(dfs(i, vis, path, adj, st))
                    return false;
            }
        }

        return true;
    }
};