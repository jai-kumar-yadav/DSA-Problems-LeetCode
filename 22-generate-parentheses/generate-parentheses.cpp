class Solution {
private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: if the current string has reached the maximum length
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // Try adding an opening bracket if we haven't used all n of them
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // Try adding a closing bracket if it won't exceed the number of opening brackets
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};