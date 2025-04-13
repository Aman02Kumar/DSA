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

        int i =0; int j =0;
        if(a.length() != b.length()) return false;

        while(i<a.length()){
            if(a[i] != b[j]) return false;
            i++;
            j++;
        }

        return true;


    }
};