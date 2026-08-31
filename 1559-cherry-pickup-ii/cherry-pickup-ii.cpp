class Solution {
public:
    int f(int i, int j1, int j2,
          vector<vector<vector<int>>>& dp,
          vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Invalid position
        if (j1 < 0 || j2 < 0 ||
            j1 >= m || j2 >= m) {
            return -1e9;
        }

        // Last row
        if (i == n - 1) {

            if (j1 == j2) {
                return grid[i][j1];
            }

            return grid[i][j1] + grid[i][j2];
        }

        // Already calculated
        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int ans = -1e9;

        // Robot 1: j1-1, j1, j1+1
        // Robot 2: j2-1, j2, j2+1

        for (int l = -1; l <= 1; l++) {

            for (int k = -1; k <= 1; k++) {

                int value;

                if (j1 == j2) {
                    value = grid[i][j1];
                }
                else {
                    value = grid[i][j1] + grid[i][j2];
                }

                value += f(
                    i + 1,
                    j1 + l,
                    j2 + k,
                    dp,
                    grid
                );

                ans = max(ans, value);
            }
        }

        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(m, -1)
            )
        );

        return f(0, 0, m - 1, dp, grid);
    }
};