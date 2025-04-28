class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n<3) return 0;
        int i = 0, j = 1;
        int diff = -2001;
        while(j<n){
            if(diff==-2001) diff = nums[j]-nums[i];
            if(nums[j]-nums[j-1]==diff){
                if(j-i+1<3) j++;
                else{
                    ans+=j-i-1;
                    j++;
                }
            }else{
                i = j-1;
                diff = -2001;
            }
        }
        return ans;
    }
};