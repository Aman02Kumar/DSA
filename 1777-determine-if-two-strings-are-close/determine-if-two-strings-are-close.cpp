class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();

        if(n != m) return false;

        vector<int> f1(26, 0), f2(26, 0);

        for(int i = 0; i < n; i++){
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }

        // Check if both words contain the same characters
        for(int i = 0; i < 26; i++){
            if((f1[i] == 0 && f2[i] != 0) || (f1[i] != 0 && f2[i] == 0))
                return false;
        }

        // Check if frequency multisets match
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        return f1 == f2;
    }
};
