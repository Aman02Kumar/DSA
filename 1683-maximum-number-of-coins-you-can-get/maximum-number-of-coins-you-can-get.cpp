class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int totalCoins = 0;
        for (int i = n / 3; i < n; i += 2) {
            totalCoins += piles[i];
        }
        return totalCoins;
    }
};