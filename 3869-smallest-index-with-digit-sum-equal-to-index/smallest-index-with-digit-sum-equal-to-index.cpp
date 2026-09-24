class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int digitSum = 0;
            int temp = nums[i];
            
            // Calculate the sum of the digits of nums[i]
            while (temp > 0) {
                digitSum += temp % 10;
                temp /= 10;
            }
            
            // Handle the case where nums[i] is 0
            if (nums[i] == 0) {
                digitSum = 0;
            }
            
            if (digitSum == i) {
                return i;
            }
        }
        return -1;
    }
};