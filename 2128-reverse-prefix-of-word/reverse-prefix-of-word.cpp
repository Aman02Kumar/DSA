class Solution {
public:
    void find(string &word, int i){
        int l = 0 ; int r = i;
        while(l<=r){
            char ch = word[l];
            word[l] = word[r];
            word[r] = ch;
            l++;
            r--;
        }
    }
    string reversePrefix(string word, char ch) {
        int ind = 0 ;
        for(int i = 0 ; i <word.size();i++){
            if(word[i] == ch){
                ind = i;
                break;
            }
        }

        find(word,ind);
        return word;
    }
};