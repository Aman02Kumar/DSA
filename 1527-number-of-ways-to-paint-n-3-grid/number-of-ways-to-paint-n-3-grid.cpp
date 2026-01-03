class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1000000007;
        long long A = 0, B = 1, C = 1, D = 0;
        for (int x = n - 1; x > 0; x >>= 1) {
            if (x & 1) {
                long long nextA = (A*D + B*C + 5*A*C) % MOD;
                long long nextB = (B*D - 2*A*C) % MOD;
                A = nextA, B = nextB;
            }
            long long nextC = (2*C*D + 5*C*C) % MOD;
            long long nextD = (D*D - 2*C*C) % MOD;
            C = nextC, D = nextD;
        }
        return (54*A + 12*B + MOD*MOD) % MOD;
    }
};