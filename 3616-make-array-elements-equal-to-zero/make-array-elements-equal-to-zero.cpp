class Solution {
public:


    bool valid(vector<int>nums , int curr , int dir){

            // nums , 1 , 1
            while(curr >= 0 && curr < nums.size()){

                if(nums[curr] ==0){
                    curr += dir;
                }
                else{
                    nums[curr]--;
                    dir = -dir;
                    curr += dir;
                }


            }
            for(auto i : nums){
                if(i != 0) return false;
            }
            return true;
    }

    int countValidSelections(vector<int>& nums) {
        
        int cnt= 0;
        for(int i = 0 ; i<nums.size();i++){

            if(nums[i] == 0){
                cnt += valid(nums,i,1);
                cnt += valid(nums,i,-1);
            }
        }
        return cnt;
    }
};