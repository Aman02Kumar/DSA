class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mpp;

    // Count occurrences of each char
    for (auto it : s) {
        mpp[it]++;
    }

    // Store the frequency of first character
    int cnt = mpp[s[0]];  

    // Check if all characters have the same frequency
    for (auto it : mpp) {
        if (cnt != it.second) {
            return false;
        }
    }
    return true;
    }
};
