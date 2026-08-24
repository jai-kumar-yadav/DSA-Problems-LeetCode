#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        std::vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }
        
        // Base case: when only 2 stones are left, the only move is to take both.
        // The score difference is prefixSum[n].
        int res = prefixSum[n];
        
        // Iterate backwards from n - 1 down to 2
        for (int i = n - 1; i >= 2; --i) {
            res = std::max(res, prefixSum[i] - res);
        }
        
        return res;
    }
};