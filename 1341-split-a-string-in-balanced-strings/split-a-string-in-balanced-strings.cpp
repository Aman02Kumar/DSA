class Solution {
public:
    int balancedStringSplit(string s) {
        
        int ans = 0 ;
        int check = 0;
        for(auto i : s){
            if(i =='R'){
                    check++;
            }
            else check--;
            if(check ==0 )ans++;
        }
        return ans;
    }
};