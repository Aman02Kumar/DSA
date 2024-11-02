class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> arr_mapping;
        int r = nums2.size() - 1;
        stack<int> st;
        while (r >= 0) {
            while (!st.empty() && st.top() <= nums2[r]) {
                st.pop();
            }
            if (st.empty()) {
                arr_mapping[nums2[r]] = -1;
            } else {
                arr_mapping[nums2[r]] = st.top();
            }
            st.push(nums2[r]);
            --r;
        }

        for(r = 0; r<nums1.size();++r) {
            nums1[r] = arr_mapping[nums1[r]];
        }
        return nums1;
 
    }
};