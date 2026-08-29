#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find the break point (first element from right that is smaller than its next)
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // If no break point exists, the array is in descending order; reverse it to get the lowest permutation
        if (idx == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest element greater than nums[idx] to the right of idx
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                std::swap(nums[i], nums[idx]);
                break;
            }
        }

        // Step 3: Reverse the elements from idx + 1 to the end to get the smallest lexicographical order
        std::reverse(nums.begin() + idx + 1, nums.end());
    }
};