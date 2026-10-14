class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || (long long)num * 9 < sum) {
            return "";
        }
        
        string ans = "";
        for (int i = 0; i < num; ++i) {
            int remaining_slots = num - 1 - i;
            int cur = min(9, sum - remaining_slots * 0);
            if (sum - cur > remaining_slots * 9) {
                cur = sum - remaining_slots * 9;
            }
            ans += to_string(cur);
            sum -= cur;
        }
        
        return ans;
    }
};