class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int m = s.size();
        string ans(m, ' ');
        int x = 0;
        for(int i = 0 ; i < s.size(); i++){
            x = indices[i];
            ans[x] = s[i];
        }

        return ans;

    }
};