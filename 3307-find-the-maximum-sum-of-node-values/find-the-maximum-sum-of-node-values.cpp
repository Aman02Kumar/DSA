class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int count = 0;
        long long min_extra = INT_MAX;

        for (int val: nums){
            if ((val ^ k) > val){
                sum += (val ^ k);
                min_extra = min(min_extra,(long long)((val ^ k) - val));
                count += 1;
            }
            else {
                sum += val;
                min_extra = min(min_extra,(long long)(val - (val ^ k)));
            }
        }
        if (count % 2) return sum - min_extra;
        return sum;
    }
};