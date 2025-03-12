class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         int sLen = s.length(), pLen = p.length();
    if (sLen < pLen) return {};

    vector<int> pCount(26, 0), sCount(26, 0), result;


    for (char c : p) pCount[c - 'a']++;

    for (int i = 0; i < pLen; i++) sCount[s[i] - 'a']++;


    if (pCount == sCount) result.push_back(0);
    for (int i = pLen; i < sLen; i++) {
        sCount[s[i] - 'a']++;           
        sCount[s[i - pLen] - 'a']--;      
        if (pCount == sCount) result.push_back(i - pLen + 1);
    }

    return result;
    }
};