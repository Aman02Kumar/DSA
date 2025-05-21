class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

    // 1. Count frequency
    for (char c : s) {
        freq[c]++;
    }

    // 2. Find first unique character
    for (int i = 0; i < s.length(); i++) {
        if (freq[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}
};