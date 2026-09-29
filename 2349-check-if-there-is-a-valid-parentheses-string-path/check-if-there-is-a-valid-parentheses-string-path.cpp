class Solution {
    int m, n;
    int memo[100][100][201];

    bool dfs(int r, int c, int count, vector<vector<char>>& grid) {

        // Add current cell
        count += (grid[r][c] == '(' ? 1 : -1);

        // Invalid if closing brackets exceed opening brackets
        if (count < 0)
            return false;

        // Destination cell
        if (r == m - 1 && c == n - 1)
            return count == 0;

        // Already calculated
        if (memo[r][c][count] != -1)
            return memo[r][c][count];

        bool ans = false;

        // Move Down
        if (r + 1 < m)
            ans = dfs(r + 1, c, count, grid);

        // Move Right
        if (!ans && c + 1 < n)
            ans = dfs(r, c + 1, count, grid);

        return memo[r][c][count] = ans;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Total path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        memset(memo, -1, sizeof(memo));

        return dfs(0, 0, 0, grid);
    }
};