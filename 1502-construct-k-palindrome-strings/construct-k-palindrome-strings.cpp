class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(k>n)return false;
        if(n==k)return true;
        vector<int> f(26,0);
        for(auto &it:s)f[it-'a']++;
        int cnt=0;
        for(auto &it:f)if(it%2!=0)cnt++;
        if(cnt<=k)return true;
        return false;
    }
};