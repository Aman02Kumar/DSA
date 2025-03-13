class Solution {
public:
    bool isMappingConsistent(string s, string t) {
        map<char, char> mpStr;
        if (s.size() != t.size()) return false;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (mpStr.find(s[i]) == mpStr.end()) {
                mpStr[s[i]] = t[i];
            } else if (mpStr[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }

    bool isIsomorphic(string s, string t) {
        return isMappingConsistent(s, t) && isMappingConsistent(t, s);
    }
};

