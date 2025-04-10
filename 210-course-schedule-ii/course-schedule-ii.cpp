class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        int count = 0;
        
        // Build the adjacency list and calculate indegree
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        // Add all nodes with indegree 0 to the queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            count++;
            
            for (int i = 0; i < adj[curr].size(); i++) {
                indegree[adj[curr][i]]--;
                if (indegree[adj[curr][i]] == 0) {
                    q.push(adj[curr][i]);
                }
            }
        }
        
        // If all courses are not completed, return an empty array
        if (count == numCourses) {
            return ans;
        } else {
            return {};
        }
    }
};
