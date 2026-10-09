class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open_brackets = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // If we have an odd number of open brackets and encounter '(', 
                // we need to insert a ')' to close the previous unmatched single ')'.
                if (open_brackets % 2 != 0) {
                    insertions++;
                    open_brackets--;
                }
                open_brackets += 2;
            } else {
                open_brackets--;
                // If open_brackets is negative, we have an extra ')' without an open '('
                if (open_brackets < 0) {
                    insertions++; // Insert '('
                    open_brackets += 2; // Treat it as a valid pair '()' or need one more ')'
                }
            }
        }
        
        // Any remaining open brackets need two closing parentheses each
        return insertions + open_brackets;
    }
};