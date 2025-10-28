class Solution {
public:
    int find(vector<int> nums, int maxi , int curr ,int ind){

        if(ind == nums.size()){
            if(curr == maxi){
                return 1;
            }
            return 0;
        }

        int l = find(nums,maxi ,curr | nums[ind], ind+1);
        int r = find(nums,maxi ,curr , ind+1);
        return l+r;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        int maxi = 0 ;
        for(auto i : nums){
            maxi |= i;
        }
        int curr = 0;
        return find(nums,maxi,curr,0);
    }
};