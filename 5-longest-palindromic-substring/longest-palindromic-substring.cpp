class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindromes (center is at i)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes (center is between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                // Calculate start index based on center and length
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return length of the palindrome found
        return right - left - 1;
    }
};