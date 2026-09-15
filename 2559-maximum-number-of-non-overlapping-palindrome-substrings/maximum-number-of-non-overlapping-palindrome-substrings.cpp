class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        // dp[i] will store the max palindromes we can form in prefix s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            // Carry forward the previous max count
            dp[i + 1] = dp[i];

            // Try to find palindromes ending at index i
            // We check odd and even length palindromes
            for (int len : {k, k + 1}) {
                int start = i - len + 1;
                if (start >= 0 && isPalindrome(s, start, i)) {
                    dp[i + 1] = max(dp[i + 1], dp[start] + 1);
                }
                
                // Also check if a slightly longer one ending at i helps
                // (Though standard greedy typically uses len = k and k+1, 
                // checking valid ranges ensures we don't miss optimal endpoints)
                int start_plus = i - (len + 1) + 1;
                if (start_plus >= 0 && isPalindrome(s, start_plus, i)) {
                    dp[i + 1] = max(dp[i + 1], dp[start_plus] + 1);
                }
            }
        }
        return dp[n];
    }

private:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};