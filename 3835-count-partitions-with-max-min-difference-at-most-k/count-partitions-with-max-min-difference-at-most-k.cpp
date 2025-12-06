class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        vector<long long> dp(n + 1), pref(n + 1);
        dp[0] = 1;
        pref[0] = 1;

        deque<int> minq, maxq;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            int x = nums[r];

            //(increasing)
            while (!minq.empty() && nums[minq.back()] >= x) {
                minq.pop_back();
            }
            minq.push_back(r);

            //(decreasing)
            while (!maxq.empty() && nums[maxq.back()] <= x) {
                maxq.pop_back();
            }
            maxq.push_back(r);

            // Shrink from left until valid........
            while (!minq.empty() && !maxq.empty()
                   && nums[maxq.front()] - nums[minq.front()] > k) {
                if (minq.front() == l) minq.pop_front();
                if (maxq.front() == l) maxq.pop_front();
                ++l;
            }

            long long base = (l > 0 ? pref[l - 1] : 0);
            long long val = (pref[r] - base) % MOD;
            if (val < 0) val += MOD;
            dp[r + 1] = val;
            pref[r + 1] = (pref[r] + dp[r + 1]) % MOD;
        }

        return (int)(dp[n] % MOD);
    }
};