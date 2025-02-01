class Solution {
public:

    int solve(int i , vector<int>& nums, int target, vector<vector<int>>&dp){

        //base case 
        if(i == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || target == nums[0]) return 1;
            return 0; 
        }

        if(dp[i][target] != -1) return dp[i][target];

        int not_pick = solve(i-1,nums,target,dp);
        int pick = 0;
        if(target >= nums[i]){
            pick = solve(i-1, nums, target - nums[i], dp);
        }

        return dp[i][target] = pick + not_pick ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;

        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
        }

        if(sum-target < 0 || (sum-target)%2 != 0) return 0;

        int s2 = (sum-target)/2;

        vector<vector<int>>dp(n,vector<int>(s2+1,-1));

        return solve(n-1,nums, s2, dp);
    }
};