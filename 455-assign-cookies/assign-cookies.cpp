class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int child = 0, cookie = 0;
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (child < n && cookie < m) {
            if (s[cookie] >= g[child]) { // If cookie can satisfy the child
                child++; // Move to the next child only if satisfied
            }
            cookie++; // Always move to the next cookie
        }
        return child;
    }
};
