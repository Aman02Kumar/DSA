class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string a ="";
        for(auto it : word1){
            a+=it;
        }

        string b ="";
        for(auto it : word2){
            b+=it;
        }

        if(a.length() != b.length()) return false;

        return a==b;


    }
};