class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int n = s.length();
        int maxlen = 0;
        vector<int> mp(256, -1); // To store last index of each character

        while (r < n) {
            if (mp[s[r]] >= l) {
                l = mp[s[r]] + 1; // move left pointer past the duplicate
            }
            maxlen = max(maxlen, r - l + 1);
            mp[s[r]] = r; // update last seen index of character
            r++;
        }
        return maxlen;
    }
};
