class Solution {
public:
    int f(int m, int n, vector<vector<int>>& matrix,
          vector<vector<int>>& dp) {

        if (m == 0) {
            return matrix[0][n];
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        int ans = 1e9;

        for (int i = 0; i < matrix[0].size(); i++) {
            if (i != n) {
                ans = min(ans, f(m - 1, i, matrix, dp));
            }
        }

        return dp[m][n] = matrix[m][n] + ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 1e9;

        for (int i = 0; i < n; i++) {
            ans = min(ans, f(m - 1, i, matrix, dp));
        }

        return ans;
    }
};