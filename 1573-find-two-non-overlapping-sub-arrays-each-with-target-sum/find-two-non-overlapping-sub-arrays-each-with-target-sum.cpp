#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] stores the minimum length of a subarray with sum = target ending at or before index i
        std::vector<int> min_len(n, INT_MAX);
        
        int sum = 0;
        int left = 0;
        int min_so_far = INT_MAX;
        int result = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Shrink the window from the left if the sum exceeds the target
            while (sum > target) {
                sum -= arr[left++];
            }
            
            // If we found a valid subarray with sum == target
            if (sum == target) {
                int curr_len = right - left + 1;
                
                // Check if there is a valid non-overlapping subarray before this one
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    result = std::min(result, curr_len + min_len[left - 1]);
                }
                
                // Update min_so_far with the minimum length found up to the current index
                min_so_far = std::min(min_so_far, curr_len);
            }
            
            // Store the minimum length ending at or before index 'right'
            min_len[right] = min_so_far;
        }
        
        return result == INT_MAX ? -1 : result;
    }
};