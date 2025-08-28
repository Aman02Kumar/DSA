class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int count = 0;
        unordered_set<char> vowels = {'a','e','i','o','u'};

        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;
            for (int j = i; j < n; j++) {
                if (vowels.count(word[j]) == 0) break; // stop if not vowel
                seen.insert(word[j]);
                if (seen.size() == 5) count++;
            }
        }
        return count;
    }
};