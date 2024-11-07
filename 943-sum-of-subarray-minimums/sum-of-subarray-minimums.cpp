class Solution {
public:
    vector<int> nextSmallerElementRight(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if (st.empty())
                ans.push_back(nums.size());
            else
                ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> nextSmallerElementLeft(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());

            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left = nextSmallerElementLeft(arr);
        vector<int> right = nextSmallerElementRight(arr);

        long long int count = 0;
        long long mod = 1e9 +7;
        for (int i = 0; i < arr.size(); i++) {
            cout<<left[i]<<" "<<right[i]<<"  ";
            count += (abs(left[i] - i)%mod * abs(right[i] - i)%mod * arr[i]%mod)%mod;
        }
        return count%mod;
    }
};