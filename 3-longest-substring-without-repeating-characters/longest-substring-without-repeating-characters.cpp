class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(128, -1); // Stores last index of each char
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            // If character already exists in the current window
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            
            // Update last seen index
            charIndex[s[right]] = right;
            
            // Update max length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};