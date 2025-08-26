class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxidx = 0;
        int n = nums.size();
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(maxidx < i)  return false;
            maxidx = max(i + nums[i],maxidx);
        }
        return true;
    }
};