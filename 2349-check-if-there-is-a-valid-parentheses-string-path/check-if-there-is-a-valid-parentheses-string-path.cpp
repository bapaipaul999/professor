class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 != 0)
            return false;

        vector<vector<vector<bool>>> dp(
            n,
            vector<vector<bool>>(m, vector<bool>(n * m + 1, false))
        );

        int start = (grid[0][0] == '(' ? 1 : -1);

        if (start < 0)
            return false;

        dp[0][0][start] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                for (int balance = 0; balance <= n * m; balance++) {

                    if (!dp[i][j][balance])
                        continue;

                    // Go down
                    if (i + 1 < n) {
                        int nb = balance + (grid[i + 1][j] == '(' ? 1 : -1);

                        if (nb >= 0)
                            dp[i + 1][j][nb] = true;
                    }

                    // Go right
                    if (j + 1 < m) {
                        int nb = balance + (grid[i][j + 1] == '(' ? 1 : -1);

                        if (nb >= 0)
                            dp[i][j + 1][nb] = true;
                    }
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};