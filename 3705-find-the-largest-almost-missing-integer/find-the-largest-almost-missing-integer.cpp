class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: k == 1
        if (k == 1) {
            unordered_map<int, int> freq;
            for (int x : nums) {
                freq[x]++;
            }
            int ans = -1;
            for (auto& [val, count] : freq) {
                if (count == 1) {
                    ans = max(ans, val);
                }
            }
            return ans;
        }
        
        // Case 2: k == n
        if (k == n) {
            int max_val = -1;
            for (int x : nums) {
                max_val = max(max_val, x);
            }
            return max_val;
        }
        
        // Case 3: 1 < k < n
        // Check frequencies of nums[0] and nums[n - 1] in the entire array
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        
        int ans = -1;
        // Check first element
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        // Check last element
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }
        
        return ans;
    }
};