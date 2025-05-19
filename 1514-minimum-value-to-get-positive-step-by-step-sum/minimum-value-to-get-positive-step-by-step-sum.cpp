class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minSum = INT_MAX;

        for (int num : nums) {
            sum += num;
            minSum = min(minSum, sum);
        }

        return minSum < 0 ? 1 - minSum : 1;
    }
};
