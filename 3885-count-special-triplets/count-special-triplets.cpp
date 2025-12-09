class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        if (nums.empty()) return 0;
        const long long MOD = 1000000007LL;

        unordered_map<long long, long long> rightFreq;
        rightFreq.reserve(nums.size()*2);
        unordered_map<long long, long long> leftFreq;
        leftFreq.reserve(nums.size()*2);

        for (int x : nums) rightFreq[x]++;

        long long count = 0;
        for (int x : nums) {
            rightFreq[x]--;
            long long req = (long long)x * 2;
            auto itL = leftFreq.find(req);
            auto itR = rightFreq.find(req);
            if (itL != leftFreq.end() && itR != rightFreq.end()) {
                count = (count + (itL->second * itR->second) % MOD) % MOD;
            }
            leftFreq[x]++;
        }

        return (int)count;
    }
};