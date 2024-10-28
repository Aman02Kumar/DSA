class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // Sort the greed factor array
        sort(s.begin(), s.end());  // Sort the cookie size array
        
        int m = s.size();  // Number of cookies
        int n = g.size();  // Number of children
        int l = 0;  // Pointer for cookies
        int r = 0;  // Pointer for children

        // Iterate through cookies and children
        while (l < m && r < n) {
            if (g[r] <= s[l]) {  // If the current child can be content with the cookie
                r++;  // Move to the next child
            }
            l++;  // Move to the next cookie
        }
        
        return r;  // The number of content children
    }
};