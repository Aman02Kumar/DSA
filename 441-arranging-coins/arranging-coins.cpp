class Solution {
public:
    int arrangeCoins(int n) {
        int l =1 ;
        int r = n;
        int ans = n ;
        while(l<=r){
           int m = l + (r - l) / 2;

            long  need =(long) m*(m+1)/2;
            if(need == n) return m;
            else if(need > n){
                
                r  = m -1;

            }
            else {
                ans = m;
                l = m +1;
            }
        }
        return ans;
    }
};