class Solution {
public:
    void find(vector<int> &nums, vector<int> &temp, vector<bool> &visited, vector<vector<int>> &ans) {
        int n = nums.size();

        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                temp.push_back(nums[i]);
                find(nums, temp, visited, ans);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> visited(n, 0);
        vector<int> temp;

        find(nums, temp, visited, ans);
        return ans;
    }
};
