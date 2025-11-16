class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l = 0 ;
        int r = 0;
        int len = 0;
        while(r<s.size()){

            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            len = max(len , r-l+1);
            r++;

        }
        return len;
    }
};