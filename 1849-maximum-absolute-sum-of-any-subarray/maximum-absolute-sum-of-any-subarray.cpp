class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxs = INT_MIN;

        int s = 0 ;
        for(auto i : nums){

            s += i;
            maxs = max(s,maxs);
            if(s<0){
                s = 0;
            }
        }

        int mins = INT_MIN;
         for (int i = 0; i < nums.size(); i++) {
            nums[i] = -nums[i];  // Correctly flip using index
        }

        s = 0 ;
        for(auto i : nums){

            s += i;
            mins = max(s,mins);
            if(s<0){
                s = 0;
            }
        }
        return max(mins,maxs);
    }
};