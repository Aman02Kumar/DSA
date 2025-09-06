class Solution {
public:
    long long minOperations(vector<vector<int>>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long l = nums[i][0];
            long long r = nums[i][1];
            if (l < 4 && r < 4) {
                ans += ceil((r - l + 1) / 2.0);
            }
            else{
                long long total = 0;
                long long start = 1, steps = 1;
                while (start <= r) {
                    long long end = start * 4 - 1;
                    long long left = max(l, start);
                    long long right = min(r, end);

                    if (left <= right) {
                        long long count = right - left + 1;
                        total += count * steps;
                    }

                    start *= 4;
                    steps++;
                }
                ans += (total + 1) / 2;
            }
        }
        return ans;
    }
};