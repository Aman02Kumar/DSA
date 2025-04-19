class Solution {
public:
    int distinctAverages(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        set<double> my;
        for(int i=0;i<nums.size()/2;i++)
        my.insert((double)(nums[i]+nums[nums.size()-i-1])/2);
        return my.size(); 
    }
};