class Solution {
public:

    void find(vector<int>& nums , vector<vector<int>> &ans , int index ){

        int n = nums.size();
        if(index >= n){
            ans.push_back(nums);
            return;
        }

        for(int i= index ; i < n ; i++){

                swap(nums[index],nums[i]);
                find(nums,ans,index+1);
                 swap(nums[index],nums[i]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int >> ans;
        int index = 0 ;
        find(nums , ans , index);
        return ans;
    }
};