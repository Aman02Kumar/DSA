class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX); // Store min frequency of each letter
        
        for (const string& word : words) {
            vector<int> freq(26, 0);
            
            // Count frequency of each character in the current word
            for (char c : word) {
                freq[c - 'a']++;
            }
            
            // Update minFreq to store the minimum count across words
            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }
        
        // Build the result
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (minFreq[i] > 0) {
                result.push_back(string(1, 'a' + i));
                minFreq[i]--;
            }
        }
        
        return result;
    }
};
