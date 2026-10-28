class Solution {
public:
    int f(int i, int j, int xr, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        xr ^= grid[i][j];

        if (i == m - 1 && j == n - 1) {
            return xr;
        }

        if (dp[i][j][xr] != -1) {
            return dp[i][j][xr];
        }

        int down = INT_MAX;
        int right = INT_MAX;

        if (i < m - 1) {
            down = f(i + 1, j, xr, grid, dp);
        }

        if (j < n - 1) {
            right = f(i, j + 1, xr, grid, dp);
        }

        return dp[i][j][xr] = min(down, right);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(1024, -1))
        );

        return f(0, 0, 0, grid, dp);
    }
};