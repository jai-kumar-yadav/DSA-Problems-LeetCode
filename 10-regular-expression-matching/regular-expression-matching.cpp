#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] represents whether s[i:] and p[j:] match
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Empty pattern and empty string match
        dp[m][n] = true;
        
        // Fill the table from bottom-up
        for (int i = m; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                bool first_match = (i < m && (p[j] == s[i] || p[j] == '.'));
                
                if (j + 1 < n && p[j + 1] == '*') {
                    // Two choices: 
                    // 1. Zero occurrences of the preceding element (skip p[j] and p[j+1])
                    // 2. One or more occurrences (if first_match is true, move to next char in s)
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } else {
                    // Standard match: must have first_match and match remaining suffixes
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        
        return dp[0][0];
    }
};
