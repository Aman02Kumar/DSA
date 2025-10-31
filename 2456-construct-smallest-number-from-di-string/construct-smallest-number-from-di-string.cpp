class Solution {
public:
    string smallestNumber(string p) {
        stack<int> st;
        int cnt = 1;
        st.push(cnt);
        string ans = "";

        for (auto i : p) {
            if (i == 'I') {
                while (!st.empty()) {
                    ans += st.top() + '0';
                    st.pop();
                }
            }
            cnt++;
            st.push(cnt);
        }
        while (!st.empty()) {
            ans += st.top() + '0';
            st.pop();
        }
        return ans;
    }
};