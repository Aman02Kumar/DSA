class Solution {
public:
    int helper(vector<int> & nums , int index, int sum){

        if(index == nums.size()) return sum;

        int in = helper(nums, index+1 , sum ^ nums[index]);
        int out = helper(nums, index+1 , sum);

        return in + out;
    }
    int subsetXORSum(vector<int>& nums) {
       return helper(nums,0,0); 
    }
};