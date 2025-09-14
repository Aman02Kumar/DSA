class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }

    string devowel(string s) {
        for (char &c : s) {
            if (isVowel(c)) c = '#';
            else c = tolower(c);
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string,string> lowerMap, vowelMap;

        for (auto &w : wordlist) {
            string lower = toLower(w);
            string dev = devowel(w);

            if (!lowerMap.count(lower)) lowerMap[lower] = w;
            if (!vowelMap.count(dev)) vowelMap[dev] = w;
        }

        vector<string> result;
        for (auto &q : queries) {
            if (words.count(q)) { 
                result.push_back(q);
            }
            else if (lowerMap.count(toLower(q))) {
                result.push_back(lowerMap[toLower(q)]);
            }
            else if (vowelMap.count(devowel(q))) { 
                result.push_back(vowelMap[devowel(q)]);
            }
            else {
                result.push_back("");
            }
        }
        return result;
    }
};