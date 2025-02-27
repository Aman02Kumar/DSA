class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (mp.find(arr[i] + arr[j]) != mp.end()) {
                    if (dp[i][j] > 0) {
                        dp[j][mp[arr[i] + arr[j]]] = dp[i][j] + 1;
                    } else {
                        dp[j][mp[arr[i] + arr[j]]] = 3;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                ans = max(dp[i][j], ans);
            }
        }
        return ans;
    }
};