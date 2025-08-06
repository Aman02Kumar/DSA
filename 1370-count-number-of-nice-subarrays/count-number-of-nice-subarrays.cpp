class Solution {
public:
    int numberOfSubarraysLessThan_K(vector<int>& nums, int k) {
    
        int left = 0,right = 0,sum = 0,cnt = 0;

        if( k < 0)
        return 0;

        while(right < nums.size()){

            sum += nums[right];  // if odd returns 1 , else 0

            while(sum > k){
                sum -= nums[left];
                left++;
            }
            if(sum <= k)
            cnt = cnt + right - left + 1;

            right++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        for(int i=0;i<nums.size();i++){
            if(nums[i] % 2 == 0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        }

        return numberOfSubarraysLessThan_K(nums,k) - numberOfSubarraysLessThan_K(nums,k-1);
    }
};