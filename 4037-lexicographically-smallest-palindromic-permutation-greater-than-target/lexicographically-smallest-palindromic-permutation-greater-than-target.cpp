#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string lexPalindromicPermutation(std::string s, std::string target) {
        int n = s.length();
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int oddCount = 0;
        int oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                oddCount++;
                oddChar = i;
            }
        }

        if (oddCount > (n % 2 == 0 ? 0 : 1)) {
            return "";
        }

        int halfLen = n / 2;
        std::string half(halfLen, ' ');
        std::string result = "";

        auto dfs = [&](auto& self, int idx, bool isGreater, std::vector<int>& cnt) -> bool {
            if (idx == halfLen) {
                std::string mid = (n % 2 != 0) ? std::string(1, (char)('a' + oddChar)) : "";
                std::string rev = half;
                std::reverse(rev.begin(), rev.end());
                std::string candidate = half + mid + rev;
                if (candidate > target) {
                    result = candidate;
                    return true;
                }
                return false;
            }

            int startChar = isGreater ? 0 : (target[idx] - 'a');
            for (int i = startChar; i < 26; i++) {
                if (cnt[i] >= 2) {
                    cnt[i] -= 2;
                    half[idx] = (char)('a' + i);
                    if (self(self, idx + 1, isGreater || (i > target[idx] - 'a'), cnt)) {
                        return true;
                    }
                    cnt[i] += 2;
                }
            }
            return false;
        };

        std::vector<int> cnt = count;
        if (n % 2 != 0) {
            cnt[oddChar]--;
        }

        if (dfs(dfs, 0, false, cnt)) {
            return result;
        }

        return "";
    }
};