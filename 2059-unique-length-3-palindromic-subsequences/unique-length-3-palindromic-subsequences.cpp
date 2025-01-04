class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int res=0;
        for(auto it: mp){
            vector<int> id = it.second;
            int start = id[0];
            int end = id[id.size()-1];
            if(end - start <=1){
                continue;
            }
            else{
                map<char, int> mpp;
                for(int i = start+1; i<end; i++){
                    mpp[s[i]]++;
                }
                res += mpp.size();
            }
        }
        return res;
    }
};