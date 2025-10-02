class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ret = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= (numExchange - 1);
            ret++;
            numExchange++;
        }
        return ret;
    }
};