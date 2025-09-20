class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> minh;

        for (int i = 0; i < nums.size(); i++) {
            minh.push(nums[i]);
        }
        k--;
        while(k){
                minh.pop();
                k--;
        }

        return minh.top();
    }
};