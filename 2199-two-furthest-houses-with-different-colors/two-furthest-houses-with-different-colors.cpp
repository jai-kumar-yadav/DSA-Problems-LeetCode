class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;
        
        for (int i = 0; i < n; ++i) {
            // Check against the last house
            if (colors[i] != colors[n - 1]) {
                maxDist = max(maxDist, n - 1 - i);
            }
            // Check against the first house
            if (colors[i] != colors[0]) {
                maxDist = max(maxDist, i);
            }
        }
        
        return maxDist;
    }
};