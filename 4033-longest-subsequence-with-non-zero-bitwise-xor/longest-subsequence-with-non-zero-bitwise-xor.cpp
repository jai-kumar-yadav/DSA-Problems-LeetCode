#include <vector>

class Solution {
public:
    int longestSubsequence(std::vector<int>& nums) {
        int xor_all = 0;
        bool all_zeros = true;
        
        for (int num : nums) {
            xor_all ^= num;
            if (num != 0) {
                all_zeros = false;
            }
        }
        
        // Case 1: If all elements are 0, no non-zero XOR subsequence can be formed.
        if (all_zeros) {
            return 0;
        }
        
        // Case 2: If the total XOR is non-zero, we can take the entire array.
        if (xor_all != 0) {
            return nums.size();
        }
        
        // Case 3: If the total XOR is 0 (and not all elements are 0), 
        // removing any single element will make the XOR non-zero.
        return nums.size() - 1;
    }
};