class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> mp(n + 1, 0);
        for(auto it : queries) {
            mp[it[0]]++;
            mp[it[1] + 1]--;
        }
        int num = 0;
        for(int i = 0; i < n; i++) {
            num += mp[i];
            if(num < nums[i]) return false;
        }
        return true;
    }
};