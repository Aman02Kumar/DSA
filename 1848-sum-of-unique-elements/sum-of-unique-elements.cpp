class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        int sum = 0;
        for (int num : nums) {
            if (map[num] == 1) {
                sum += num;
            }
        }
        return sum;
    }
};