class Solution {
public:
    void find(int n , string cur, vector<string> &ans){
        if(cur.size() == n){
            ans.push_back(cur);
            return;
        }

        find(n , cur + '1',ans);
        if(cur.size() == 0 || cur.back() != '0'){
              find(n,cur+'0',ans);
        }
      

    }

    vector<string> validStrings(int n) {
        vector <string> ans;
        find(n,"",ans);
        return ans;
    }
};