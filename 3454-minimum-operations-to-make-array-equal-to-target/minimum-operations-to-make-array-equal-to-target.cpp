class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long totalOp = 0;

        for (int prev = 0, i = 0; i < nums.size(); i++) {
            int curr = target[i] - nums[i];

            if (curr < 0 && prev >= 0 || curr > 0 && prev <= 0)
                totalOp += abs(curr);
            else if (abs(prev) < abs(curr))
                totalOp += abs(curr - prev);

            prev = curr;
        }

        return totalOp;
    }
};