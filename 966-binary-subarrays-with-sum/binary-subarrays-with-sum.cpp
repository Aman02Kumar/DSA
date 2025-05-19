class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp;
        int prefixsum=0;
        mpp[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(mpp.find(prefixsum-goal)!=mpp.end())ans+=mpp[prefixsum-goal];
            mpp[prefixsum]++;
        }
        return ans;
    }
};