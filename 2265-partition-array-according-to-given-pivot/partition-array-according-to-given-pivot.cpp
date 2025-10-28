class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());

        int a = 0, b = 0 , c = 0;

        for(auto i : nums){

            if(i <pivot) a++;
            else if(i == pivot) b++;
        
        }
        c = a +b;
        int x  = 0;

        for(int i = 0 ; i < nums.size() ;i++){

            if(nums[i]<pivot) {
                ans[x] = nums[i]; 
                x++;
            }
            else if(nums[i] == pivot) {
                ans[a] = pivot;
                a++;
            }
            else {
                ans[c] = nums[i];
                c++;
            }

        
        }
        return ans;

    }
};