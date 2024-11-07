class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }

    long long sumMin(vector<int>& arr){
        int n = arr.size();
        long long total = 0;
        vector<int> nse = findNse(arr, n), pse = findPse(arr, n);
        for(int i = 0; i < n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += right * left * arr[i];
        }
        return total;
    }

    vector<int> findNse(vector<int>& arr, int n){
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() && arr[i] < arr[st.top()]) st.pop();
            nse[i] = st.empty()? n: st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPse(vector<int>& arr, int n){
        vector<int> pse(n);
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            pse[i] = st.empty()? -1: st.top();
            st.push(i);
        }
        return pse;
    }

    long long sumMax(vector<int>& arr){
        int n = arr.size();
        vector<int> nge = findNge(arr, n), pge = findPge(arr, n);
        long long total = 0;
        for(int i = 0; i < n; i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total += right * left * arr[i];
        }
        return total;
    }

    vector<int> findNge(vector<int>& arr, int n){
        vector<int> nge(n);
        stack<int> st;
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() && arr[i] > arr[st.top()]) st.pop();
            nge[i] = st.empty()? n: st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findPge(vector<int>& arr, int n){
        vector<int> pge(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] >= arr[st.top()]) st.pop();
            pge[i] = st.empty()? -1: st.top();
            st.push(i);
        }
        return pge;
    }
};