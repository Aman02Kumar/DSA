class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum =0 ;

        for(int i =0 ; i <  k ; i++){

                sum += nums[i];
        }

        int l = 0 ;
        int r = k;

        int ans = sum;

        while(r<n){

            sum -= nums[l];
            l++;

            sum += nums[r];
            r++;
            ans = max(ans,sum);

        }
        return (double)ans/k;
    }
};