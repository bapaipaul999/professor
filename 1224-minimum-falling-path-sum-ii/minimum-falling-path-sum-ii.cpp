// class Solution {
// public:
//     int f(int m, int n, vector<vector<int>>& matrix,
//           vector<vector<int>>& dp) {

//         if (m == 0) {
//             return matrix[0][n];
//         }

//         if (dp[m][n] != -1) {
//             return dp[m][n];
//         }

//         int ans = 1e9;

//         for (int i = 0; i < matrix[0].size(); i++) {
//             if (i != n) {
//                 ans = min(ans, f(m - 1, i, matrix, dp));
//             }
//         }

//         return dp[m][n] = matrix[m][n] + ans;
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         int ans = 1e9;

//         for (int i = 0; i < n; i++) {
//             ans = min(ans, f(m - 1, i, matrix, dp));
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // First row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Remaining rows
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int ans = 1e9;

                // Choose any column except j
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        ans = min(ans, dp[i - 1][k]);
                    }
                }

                dp[i][j] = matrix[i][j] + ans;
            }
        }

        // Minimum value in last row
        int ans = 1e9;

        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[m - 1][j]);
        }

        return ans;
    }
};