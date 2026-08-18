class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int curSum = nums[i] + nums[left] + nums[right];
                
                // Update closestSum if the current sum is closer to target
                if (abs(curSum - target) < abs(closestSum - target)) {
                    closestSum = curSum;
                }
                
                if (curSum == target) {
                    return curSum;
                } else if (curSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closestSum;
    }
};