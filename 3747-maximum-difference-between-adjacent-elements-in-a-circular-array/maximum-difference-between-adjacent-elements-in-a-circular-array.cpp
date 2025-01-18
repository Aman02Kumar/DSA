class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int n = nums.size();
        int dif = INT_MIN;
        int l = 0 ;
        int r = 1;
        dif=abs(nums[l] - nums[n-1]);
        while(r<n){

            dif= max(dif,abs(nums[l]-nums[r]));
            r++;
            l++;
        }
        return dif;
      
    }
};

