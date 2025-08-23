class Solution {
public:
    int subarraySum(vector<int>& nums) {
        
        int n = nums.size();
    vector<int> prefix(n, 0);
    int sumResult = 0;

    // Compute prefix sum array
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    // Calculate subarray sums efficiently
    for (int i = 0; i < n; i++) {
        int start = max(0, i - nums[i]);
        sumResult += prefix[i] - (start > 0 ? prefix[start - 1] : 0);
    }

    return sumResult;
    }
};
