class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int s = 0;
        for(auto i : nums){
            s += i;
        }
        int x = 0;
        while(s % k != 0){
            s--;
            x++;
        }
        return x;
    }
};