class Solution {
public:
    int removeElement(vector<int>& nums, int v) {
        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {

            // Find v from left
            while (i <= j && nums[i] != v) {
                i++;
            }

            // Find non-v from right
            while (i <= j && nums[j] == v) {
                j--;
            }

            if (i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        return i;
    }
};