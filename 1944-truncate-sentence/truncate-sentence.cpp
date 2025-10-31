class Solution {
public:
    string truncateSentence(string s, int k) {
        int idx = 0 ;
        string ans = "";
        for(int i = 0 ; i < s.size();i++){
        
            if(s[i] ==' ') k--;
            if(k == 0) {
                    idx = i;
                    break;
            } 
            ans+=s[i];  
        }

        return ans;
    }
};