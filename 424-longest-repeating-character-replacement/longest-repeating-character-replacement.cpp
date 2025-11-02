class Solution {
public:
    int characterReplacement(string s, int k) {
        
        map<char, int> mp;
        int l = 0 ;
        int maxx = 0;
        int maxcnt = 0;

        for(int r = 0 ; r <s.size();r++){

            mp[s[r]]++;
            maxcnt = max(maxcnt , mp[s[r]] );

            while((r-l+1) - maxcnt > k ){
                mp[s[l]]--;
                l++;
            }

            maxx = max(maxx,r-l+1);
        }
        return maxx;
    }
};