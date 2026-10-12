class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(30, 0);
        
        // Count the frequency of set bits at each position
        for (int x : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((x >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        
        long long totalSum = 0;
        long long MOD = 1e9 + 7;
        
        // Greedily build the top k numbers
        for (int step = 0; step < k; ++step) {
            long long currentNum = 0;
            for (int i = 0; i < 30; ++i) {
                if (bitCount[i] > 0) {
                    currentNum |= (1 << i);
                    bitCount[i]--;
                }
            }
            totalSum = (totalSum + (currentNum * currentNum) % MOD) % MOD;
        }
        
        return totalSum;
    }
};