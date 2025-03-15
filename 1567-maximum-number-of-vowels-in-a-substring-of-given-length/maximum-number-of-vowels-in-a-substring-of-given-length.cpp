class Solution {
public:
     bool isVowel(char &ch){
        return ch == 'a'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int maxVowels(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int maxi = 0;
        int vowelCount = 0;

        while(j < n){
            if(isVowel(s[j])){
                vowelCount++;
            }

            if(j-i+1 == k){
                maxi = max(maxi, vowelCount);
                if(isVowel(s[i])){
                    vowelCount--;
                }
                i++;
            }
            j++;
        }
        return maxi;
    }
};