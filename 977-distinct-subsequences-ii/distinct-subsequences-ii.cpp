class Solution {
public:
    int distinctSubseqII(string s) {
        long long dp[26] = {0};
        long long MOD = 1e9 + 7;
        
        for (char c : s) {
            long long total = 1;
            for (int i = 0; i < 26; ++i) {
                total = (total + dp[i]) % MOD;
            }
            dp[c - 'a'] = total;
        }
        
        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + dp[i]) % MOD;
        }
        
        return ans;
    }
};
