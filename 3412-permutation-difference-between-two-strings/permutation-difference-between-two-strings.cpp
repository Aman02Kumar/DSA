class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> indexMap;
        int n = s.length();
        
        // Store indices of characters in t
        for (int i = 0; i < n; i++) {
            indexMap[t[i]] = i;
        }
        
        int totalDifference = 0;
        // Calculate sum of absolute differences
        for (int i = 0; i < n; i++) {
            totalDifference += abs(i - indexMap[s[i]]);
        }
        
        return totalDifference;
    }
};
