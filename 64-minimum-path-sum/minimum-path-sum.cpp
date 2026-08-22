class Solution {
public:
    int f(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if(m == 0 && n == 0) {
            return grid[0][0];
        }

        if(m < 0 || n < 0) {
            return 1e9;
        }

        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        int l = grid[m][n] + f(m - 1, n, dp, grid);
        int r = grid[m][n] + f(m, n - 1, dp, grid);

        return dp[m][n] = min(l, r);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, dp, grid);
    }
};