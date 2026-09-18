#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> maxNumOfSubstrings(std::string s) {
        int n = s.length();
        std::vector<int> left(26, -1), right(26, -1);

        // Step 1: Find the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (left[c] == -1) left[c] = i;
            right[c] = i;
        }

        auto getValidSubstringRight = [&](int i) {
            int r = right[s[i] - 'a'];
            for (int j = i; j <= r; ++j) {
                int c = s[j] - 'a';
                if (left[c] < i) return -1; // Invalid, expands beyond left boundary
                r = std::max(r, right[c]);
            }
            return r;
        };

        // Step 2: Find all valid intervals [L, R]
        std::vector<std::pair<int, int>> intervals;
        for (int i = 0; i < n; ++i) {
            if (i == left[s[i] - 'a']) {
                int r = getValidSubstringRight(i);
                if (r != -1) {
                    intervals.push_back({i, r});
                }
            }
        }

        // Step 3: Greedy interval scheduling (sort by end time)
        std::vector<std::string> result;
        int prev_end = -1;
        for (auto& interval : intervals) {
            int l = interval.first;
            int r = interval.second;
            if (l > prev_end) {
                result.push_back(s.substr(l, r - l + 1));
                prev_end = r;
            } else {
                // If intervals overlap, pick the one with the smaller end
                if (r < prev_end) {
                    result.back() = s.substr(l, r - l + 1);
                    prev_end = r;
                }
            }
        }

        return result;
    }
};