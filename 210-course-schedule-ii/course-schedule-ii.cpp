class Solution {
public:

    bool dfs(int i,
             vector<int>& vis,
             vector<int> adj[],
             stack<int>& st,
             vector<int>& path) {

        vis[i] = 1;
        path[i] = 1;

        for(auto it : adj[i]) {

            if(!vis[it]) {

                if(dfs(it, vis, adj, st, path)) {
                    return true;
                }
            }
            else if(path[it]) {

                return true;
            }
        }

        path[i] = 0;
        st.push(i);

        return false;
    }

    vector<int> findOrder(int v, vector<vector<int>>& pre) {

        vector<int> adj[v];

        for(auto i : pre) {
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(v, 0);
        vector<int> path(v, 0);

        stack<int> st;

        for(int i = 0; i < v; i++) {

            if(!vis[i]) {

                if(dfs(i, vis, adj, st, path)) {
                    return {};
                }
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};