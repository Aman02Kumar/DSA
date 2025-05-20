class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) { // Even number
                swap(nums[i], nums[j]); // Place it at the front
                j++;
            }
        }

        return nums;
    }
};
