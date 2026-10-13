class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squared(n);
        
        // Step 1: Compute the square of each element
        for (int i = 0; i < n; ++i) {
            squared[i] = 1LL * nums[i] * nums[i];
        }
        
        // Step 2: Sort the squared values in ascending order
        sort(squared.begin(), squared.end());
        
        long long totalScore = 0;
        
        // Step 3: Subtract the smaller half and add the larger half
        int mid = n / 2;
        for (int i = 0; i < mid; ++i) {
            totalScore -= squared[i];
        }
        for (int i = mid; i < n; ++i) {
            totalScore += squared[i];
        }
        
        return totalScore;
    }
};