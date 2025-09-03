class Solution {
public:
    bool isPalindrome(string s) {
        int pp = s.length();
        int l = 0 ;
        int r = pp -1;
        while(l<r){
            while(l<r && !isalnum(s[l]) ) l++;
            while(l<r && !isalnum(s[r]) ) r--;

            if(tolower(s[l] )!=tolower( s[r])) return false;
            r--;
            l++;
        }
        return true;
    }
};