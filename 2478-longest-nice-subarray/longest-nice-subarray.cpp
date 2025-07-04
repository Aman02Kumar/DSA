class Solution {
public:
    bool isNice(vector<int>& nums, int start, int end) {
        int mask = 0;
        for (int i = start; i <= end; i++) {
            if ((mask & nums[i]) != 0) 
                return false;
            mask |= nums[i];
        }
        return true;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isNice(nums, i, j)) {
                    result = max(result, j - i + 1);
                } else {
                    break; // No need to check further, as adding more elements will keep failing
                }
            }
        }

        return result;
    }
};