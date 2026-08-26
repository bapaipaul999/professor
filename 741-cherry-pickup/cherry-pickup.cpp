class Solution {
public:
    int f(int r1, int c1, int r2,
          vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {

        int n = grid.size();

        int c2 = r1 + c1 - r2;

        // Out of bounds
        if (r1 >= n || c1 >= n ||
            r2 >= n || c2 >= n) {
            return -1e8;
        }

        // Thorn
        if (grid[r1][c1] == -1 ||
            grid[r2][c2] == -1) {
            return -1e8;
        }

        // Destination
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = 0;

        // If both are at different cells
        if (r1 == r2 && c1 == c2) {
            cherries = grid[r1][c1];
        }
        else {
            cherries = grid[r1][c1] + grid[r2][c2];
        }

        // Four possible combinations
        int a = f(r1 + 1, c1, r2 + 1, grid, dp);
        int b = f(r1 + 1, c1, r2, grid, dp);
        int c = f(r1, c1 + 1, r2 + 1, grid, dp);
        int d = f(r1, c1 + 1, r2, grid, dp);

        int best = max({a, b, c, d});

        return dp[r1][c1][r2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n, -1)
            )
        );

        int ans = f(0, 0, 0, grid, dp);

        return max(0, ans);
    }
};