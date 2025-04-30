class Solution {
public:
    bool evenDigit(int num) {
        int count = 0;
        while (num != 0) {
            num /= 10;
            count++;
        }
        return count % 2 == 0;
    }

    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int num : nums) {
            if (evenDigit(num)) {
                cnt++;
            }
        }
        return cnt;
    }
};