class Solution {
public:
    int MOD = 1e9 + 7;

    int f(int i, int j, int rem,
          vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp,
          int k) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (i >= m || j >= n)
            return 0;

        rem = (rem + grid[i][j]) % k;

        // Destination
        if (i == m - 1 && j == n - 1) {
            return rem == 0;
        }

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        int right = f(i, j + 1, rem, grid, dp, k);
        int down = f(i + 1, j, rem, grid, dp, k);

        return dp[i][j][rem] = (right + down) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(k, -1))
        );

        return f(0, 0, 0, grid, dp, k);
    }
};