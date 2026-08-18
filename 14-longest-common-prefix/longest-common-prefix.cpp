class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Loop through the characters of the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            
            // Check this character against all other strings
            for (int j = 1; j < strs.size(); ++j) {
                // If index is out of bounds for the current string or characters don't match
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        // If the entire first string is a common prefix for all strings
        return strs[0];
    }
};