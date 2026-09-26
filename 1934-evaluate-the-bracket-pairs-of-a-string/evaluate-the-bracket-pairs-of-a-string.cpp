class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store key-value pairs
        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
            }
            else {
                // Find the closing bracket
                int j = i + 1;
                string key = "";

                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }

                // Replace key with value
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += "?";
                }

                // Skip the entire bracket pair
                i = j;
            }
        }

        return ans;
    }
};