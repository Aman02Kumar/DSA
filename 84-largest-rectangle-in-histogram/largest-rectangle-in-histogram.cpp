class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        int n = h.size();
        int ele;
        int nse ;
        int pse ; 
        int ans = INT_MIN ; 
        stack<int> st;
        for(int  i = 0 ; i < h.size();i++){

            while(!st.empty() && h[st.top()]  > h[i] ){

                nse = i ;
                ele = st.top();
                st.pop();
                pse = st.empty() ? -1 : st.top();
                ans = max(ans , (nse -pse -1) * h[ele]);
            }
            st.push(i);
        }

        while(!st.empty()){

            nse = n ;
            ele = st.top();
                st.pop();
                pse = st.empty() ? -1 : st.top();
                ans = max(ans , (nse -pse -1) * h[ele]);

        }
        return ans;
    }

};