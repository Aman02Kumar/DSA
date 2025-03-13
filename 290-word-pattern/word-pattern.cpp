class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s=s+' ';
        bool flag=false;
        string str="";
        vector<string> ans;
        for(int i=0;i<s.size();i++) {
            if(s[i]!=' ') {
                str+=s[i];
            }
            else {
                ans.push_back(str);
                str="";
            }
        }
        int size=ans.size();
        if(pattern.size()!=size) {
            return false;
        }
        unordered_map<char,string> mp;
        unordered_map<string,char> mp2;

        for(int i=0;i<pattern.size();i++) {
            if(mp.find(pattern[i])==mp.end() && mp2.find(ans[i])==mp2.end()) {
                mp[pattern[i]]=ans[i];
                mp2[ans[i]]=pattern[i];
            }
            else {
                if(mp[pattern[i]]!=ans[i] && mp2[ans[i]]!=pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

