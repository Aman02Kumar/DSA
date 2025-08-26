class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(),tokens.end());
        int l = 0;
        int n = tokens.size();
        int r = n-1;
        int s =  0;
        int maxscore = 0;

        while(l<=r){
            if( power >= tokens[l]){
                power -= tokens[l];
                l++;
                s++;
                maxscore = max(maxscore,s);
            }
            else if(s>0){
                power += tokens[r];
                r--;
                s--;
            }
            else {
                break; // important, otherwise infinite loop
            }
           
        }
        return maxscore;
    }
};