class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int elm;
        int nse;
        int pse;
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                elm = heights[st.top()];
                st.pop();
                nse = i;
                pse = st.empty()?-1:st.top();
                ans = max(ans,elm*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            nse = n;
            elm = heights[st.top()];
            st.pop();
            pse = st.empty()?-1:st.top();
            ans = max(ans,elm*(nse-pse-1));
        }
        return ans;
    }
};