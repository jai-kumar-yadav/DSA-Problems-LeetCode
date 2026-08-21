class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total_sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                total_sum += grid[i][j];
            }
        }
        
        // If the total sum is odd, we cannot split it into two equal integer parts
        if (total_sum % 2 != 0) {
            return false;
        }
        
        long long target = total_sum / 2;
        
        // Check for a valid horizontal cut
        long long current_row_sum = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                current_row_sum += grid[i][j];
            }
            if (current_row_sum == target) {
                return true;
            }
        }
        
        // Check for a valid vertical cut
        long long current_col_sum = 0;
        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                current_col_sum += grid[i][j];
            }
            if (current_col_sum == target) {
                return true;
            }
        }
        
        return false;
    }
};