class Solution {
public:



vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.length() < p.length())
        return result;

    vector<int> p_count(26, 0), s_count(26, 0);

    // Count frequency of characters in p
    for (char c : p)
        p_count[c - 'a']++;

    int windowSize = p.length();

    // First window
    for (int i = 0; i < windowSize; ++i)
        s_count[s[i] - 'a']++;

    if (s_count == p_count)
        result.push_back(0);

    // Slide the window
    for (int i = windowSize; i < s.length(); ++i) {
        // Add new character
        s_count[s[i] - 'a']++;
        // Remove the character going out of the window
        s_count[s[i - windowSize] - 'a']--;

        if (s_count == p_count)
            result.push_back(i - windowSize + 1);
    }

    return result;
}
}
;