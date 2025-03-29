class Solution {
public:
    string decodeMessage(string key, string message) {
        char charMap[26] = {};  // Fixed-size array for mapping
        char currentChar = 'a'; // Start mapping from 'a'

        // Step 1: Create mapping from `key`
        for (char c : key) {
            if (c != ' ' && charMap[c - 'a'] == 0) {
                charMap[c - 'a'] = currentChar++; // Assign 'a', 'b', 'c', ...
            }
        }

        // Step 2: Decode message using `charMap`
        for (char &c : message) {
            if (c != ' ') {
                c = charMap[c - 'a']; // Replace character with mapped value
            }
        }

        return message;
    }
};
