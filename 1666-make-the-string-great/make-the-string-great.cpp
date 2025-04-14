class Solution {
public:
    string makeGood(string s) {
        
        string r = "";
        for(int i = 0 ; i < s.length();i++){
        
            if(!r.empty() && (s[i] == r.back() +32  || s[i] == r.back() -32)){
                r.pop_back();
            }
            else {
                r.push_back(s[i]);
            }
         }
         return r;
    }
};