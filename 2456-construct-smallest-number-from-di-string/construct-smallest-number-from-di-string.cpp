class Solution {
public:
    bool find(string &p, string &s){
        for(int i = 0 ; i<p.size();i++){
            if((p[i] =='I' && s[i] > s[i+1] ) || ( p[i] =='D' && s[i] < s[i+1]) )   return false;
        }
        return true;
    }
    string smallestNumber(string p) {
        string s ="";
        int n = p.size();
        for(int i = 1 ; i<= n+1 ;i++){
            s.push_back(i+ '0');
        }
        while(!find(p,s)){
            next_permutation(begin(s),end(s));
        }
        return s;
    }
};