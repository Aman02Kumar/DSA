class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        
        int i = 0 ;
        int j = 0 ;
        int cnt0 = 0 ;
        int cnt1= 0 ;
        int ans = 0;

        while(j<s.size()){
           
            if(s[j] == '0') cnt0++;
            else  cnt1++;
            while(cnt1 > k && cnt0 > k){
                            if(s[i] == '0') cnt0--;
                            else cnt1--;
                            i++;
            }
            ans+= (j-i+1);
            j++;


        }
        return ans;
    }
};