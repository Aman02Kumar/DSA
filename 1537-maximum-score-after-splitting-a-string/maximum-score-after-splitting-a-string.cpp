class Solution {
public:
    int maxScore(string s) {
        int o=0;
        for(int i= 0 ; i < s.size();i++){
            if(s[i] == '1') o++;
        }

        int ans = INT_MIN;
        int z = 0;

        for(int i = 0 ; i< s.size()-1;i++){

            if(s[i] == '1'){ 
                o--;
            }
            else z++;
            ans = max(ans,z+o);
        }
        return ans;
    }
};