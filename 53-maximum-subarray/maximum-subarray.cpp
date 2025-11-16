class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        int sum = 0 ;
        int maxx = INT_MIN;
        for(int x : nums){
            if(sum< 0) sum = 0;
            sum += x;
            maxx = max(maxx , sum);
        }
        return maxx;
    }
};