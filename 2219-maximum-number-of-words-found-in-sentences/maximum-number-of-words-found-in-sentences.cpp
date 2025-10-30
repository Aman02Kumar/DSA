class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        
        int ans = 0;

        for(int i = 0 ;i<s.size();i++){
            int n = 0;
           for(int j = 0 ; j <s[i].size();j++){
                if(s[i][j]==' '){
                        n++;
                }
            }
            ans = max(ans,n);
        }
        return ans+1;
    }
};