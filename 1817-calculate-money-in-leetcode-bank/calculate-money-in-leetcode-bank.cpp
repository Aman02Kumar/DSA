class Solution {
public:
    int totalMoney(int n) {
        
        int m = 1 ;
        int sum = 0;
        int w = 0;
        while(n){
            sum += m ;
            w = m+1;
            n--;
            m++;
            int cnt = 6;
            while(n && cnt){
                sum += w;
                w++;
                n--;
                cnt--;
                
            }

        }
        return sum;
    }
};