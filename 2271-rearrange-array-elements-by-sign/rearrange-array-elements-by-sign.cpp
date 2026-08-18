class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n  =nums.size();

        vector<int> ans(n);
        int i = 0 , j = 1;
        for(auto k : nums){
            if(k>0){
                ans[i]=k;
                i = i +2;
            }
            else{
                ans[j] = k ; 
                j  = j +2;
            }
        }
        return ans;
    }
};