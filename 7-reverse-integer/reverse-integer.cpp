class Solution {
public:
    int reverse(int x) {
        int sum = 0 ;
        int last = 0 ;
        while(x != 0 ){

            if(sum > INT_MAX/10 || sum< INT_MIN/10) return 0;
            last = x%10;
            sum = sum *10;
            sum = sum + last;
            x = x/10;

            

        }
return sum;
    }
};