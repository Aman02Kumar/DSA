class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = INT_MIN;
        for(int i =0 ; i < nums.size();i++){
            int pro = 1;
            for(int j = i ; j < nums.size();j++){
                    pro = pro *nums[j];
                    ans = max(ans,pro);
            }
        }
        return ans;
    }

};