class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        unordered_set<int> st;
        int cnt = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(st.find(nums[i] - diff)  != st.end()  && st.find(nums[i] - 2*diff)  != st.end()){
                cnt++;
            }
            st.insert(nums[i]);
        }
        return cnt;
    }
};