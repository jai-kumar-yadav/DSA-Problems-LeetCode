class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int total = n + k - 1;
        int r = 2 * k;
        
        if (total < r) return 0;
        
        // Compute Combination C(total, r) modulo 10^9 + 7
        vector<long long> inverse(r + 1, 0);
        inverse[1] = 1;
        for (int i = 2; i <= r; ++i) {
            inverse[i] = (MOD - MOD / i) * inverse[MOD % i] % MOD;
        }
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (total - i + 1) % MOD;
            res = res * inverse[i] % MOD;
        }
        
        return res;
    }
};
