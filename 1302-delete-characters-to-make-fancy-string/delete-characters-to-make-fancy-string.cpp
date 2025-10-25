class Solution {
public:
    string makeFancyString(string s) {
        
        string ans ;
        ans+=s[0];
        ans+=s[1];
        if(s.length() <3) return s;

        for(int i = 2;i<s.length();i++){
            if(s[i-1] != s[i] || s[i] != s[i-2]){
                ans+=s[i];
            }

        }
        return ans;
    }
};