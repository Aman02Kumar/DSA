class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {
        if(str2.length() < str1.length()) return false;

        bool isPrefix = true;
        for(int i=0; i < str1.length(); i++) {
            if(str1[i] != str2[i]) {
                isPrefix = false;
            }
        }

        bool isSuffix = true;
        int diff = str2.length() - str1.length();
        for(int i=0; i < str1.length(); i++) {
            if(str1[i] != str2[diff + i]) {
                isSuffix = false;
            }
        }

        if(isPrefix && isSuffix)
            return true;
        return false;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int out = 0;
        for(int i = 0; i < n; i++) {
            for(int j=i+1; j < n; j++) {
                if(isPrefixAndSuffix(words[i], words[j]))
                    out++;
            }
        }
        return out;
    }
};