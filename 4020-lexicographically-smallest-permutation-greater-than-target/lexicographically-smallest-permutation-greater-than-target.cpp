#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Try to find a valid prefix of target and then make it strictly greater
        // We can backtrack using a helper or iterative stack logic.
        // Let's define a recursive DFS function to try building the string.
        
        string ans = "";
        if (dfs(0, true, count, target, ans, n)) {
            return ans;
        }
        return "";
    }

private:
    bool dfs(int index, bool isPrefix, vector<int>& count, const string& target, string& current, int n) {
        if (index == n) {
            return !isPrefix; // If isPrefix is still true, it means current == target, which is not strictly greater.
        }

        int startChar = isPrefix ? (target[index] - 'a') : 0;

        for (int c = startChar; c < 26; ++c) {
            if (count[c] > 0) {
                count[c]--;
                current.push_back('a' + c);

                bool nextIsPrefix = isPrefix && (c == (target[index] - 'a'));

                if (nextIsPrefix) {
                    // Try to continue matching the prefix
                    if (dfs(index + 1, true, count, target, current, n)) {
                        return true;
                    }
                } else {
                    // Once we are strictly greater, we just need to greedily pick the smallest available characters for the rest
                    for (int i = 0; i < 26; ++i) {
                        while (count[i] > 0) {
                            count[i]--;
                            current.push_back('a' + i);
                        }
                    }
                    return true;
                }

                current.pop_back();
                count[c]++;
            }
        }
        return false;
    }
};