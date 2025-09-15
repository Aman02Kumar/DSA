class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        unordered_set<char> st ;
        for(auto i : brokenLetters){
            st.insert(i);
        }
        int cnt = 0;
        stringstream ss(text);
        string word;
        while (ss >> word) {   // Extract words separated by spaces
            bool tt = false;
            for(auto i : word){
                if(st.find(i) != st.end()){
                     tt = true;
                    break;
                }

            }
            if(!tt) cnt++; 

    }
    return cnt;
    }
};