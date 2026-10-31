class Solution {
public:
    const int MOD = 1e9 + 7;

    int m, n;

    vector<vector<int>> dp;

    // Process movement in a particular direction
    int move(int i, int j, int dir, vector<vector<int>>& grid) {

        if (i >= m || j >= n)
            return 0;

        // Keep reflecting while encountering mirrors
        while (i < m && j < n && grid[i][j] == 1) {

            if (dir == 0) {
                // Moving right -> turn down
                i++;
                dir = 1;
            }
            else {
                // Moving down -> turn right
                j++;
                dir = 0;
            }
        }

        if (i >= m || j >= n)
            return 0;

        return solve(i, j, grid);
    }

    int solve(int i, int j, vector<vector<int>>& grid) {

        if (i >= m || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long right = move(i, j + 1, 0, grid);
        long long down = move(i + 1, j, 1, grid);

        return dp[i][j] = (right + down) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0, grid);
    }
};