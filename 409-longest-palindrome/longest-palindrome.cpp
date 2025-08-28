class Solution {
public:
    int longestPalindrome(string s) {
        if (s.length() == 1) return 1;

        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;  
        }

        int ans = 0;
        bool hasOdd = false;

        for (auto &i : mp) {
            if (i.second % 2 == 0) {
                ans += i.second;  // use all even counts
            } else {
                ans += i.second - 1; // use the maximum even part
                hasOdd = true;       // remember we saw an odd
            }
        }

        if (hasOdd) ans += 1; // place one odd character in the center
        return ans;
    }
};
