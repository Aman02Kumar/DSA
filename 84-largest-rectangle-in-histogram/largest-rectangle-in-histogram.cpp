class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        vector<int> ans(arr.size(), arr.size());  // Set default value to arr.size() for no NSE on the right
        stack<int> st;

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }

            st.push(i);  // Push index, not value
        }
        return ans;
    }

    vector<int> pse(vector<int>& arr) {
        vector<int> ans2(arr.size(), -1);  // Set default value to -1 for no PSE on the left
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans2[i] = st.top();
            }

            st.push(i);  // Push index, not value
        }
        return ans2;
    }

    int largestRectangleArea(vector<int>& arr) {
        int maxi = 0;
        vector<int> right = nse(arr);  // NSE values
        vector<int> left = pse(arr);   // PSE values

        for (int i = 0; i < arr.size(); i++) {
            int width = right[i] - left[i] - 1;
            maxi = max(maxi, arr[i] * width);
        }
        return maxi;
    }
};
