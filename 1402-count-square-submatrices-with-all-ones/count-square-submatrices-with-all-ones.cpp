class Solution {
public:

    int f(int i, int j, vector<vector<int>>& matrix,
          vector<vector<int>>& dp) {

        // Out of bounds
        if (i < 0 || j < 0)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // If current cell is 0
        if (matrix[i][j] == 0)
            return dp[i][j] = 0;

        // Look at:
        // top
        // left
        // diagonal

        int top = f(i - 1, j, matrix, dp);
        int left = f(i, j - 1, matrix, dp);
        int diagonal = f(i - 1, j - 1, matrix, dp);

        return dp[i][j] =
            1 + min({top, left, diagonal});
    }

    int countSquares(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(
            n, vector<int>(m, -1)
        );

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                ans += f(i, j, matrix, dp);
            }
        }

        return ans;
    }
};