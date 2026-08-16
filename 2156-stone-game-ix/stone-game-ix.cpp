class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        for (int stone : stones) {
            cnt[stone % 3]++;
        }
        
        // If the number of 1-remainders and 2-remainders are both 0, Alice loses.
        if (cnt[1] == 0 && cnt[2] == 0) return false;
        
        // If cnt[0] is even
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }
        
        // If cnt[0] is odd
        return abs(cnt[1] - cnt[2]) > 2;
    }
};
