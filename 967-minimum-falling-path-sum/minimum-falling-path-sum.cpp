class Solution {
public:
    int f(int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        if (m < 0 || n < 0 || n >= matrix[0].size()) {
            return 1e9;
        }

        if (m == 0) {
            return matrix[m][n];
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        int l = matrix[m][n] + f(m - 1, n - 1, matrix, dp);
        int x = matrix[m][n] + f(m - 1, n, matrix, dp);
        int r = matrix[m][n] + f(m - 1, n + 1, matrix, dp);

        return dp[m][n] = min(l, min(x, r));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        // Base case: first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill the remaining rows
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int left = 1e9;
                int up = dp[i - 1][j];
                int right = 1e9;

                if (j > 0)
                    left = dp[i - 1][j - 1];

                if (j < n - 1)
                    right = dp[i - 1][j + 1];

                dp[i][j] = matrix[i][j] + min(left, min(up, right));
            }
        }

        // Answer can end at any column
        int ans = 1e9;

        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[m - 1][j]);
        }

        return ans;
    }
};