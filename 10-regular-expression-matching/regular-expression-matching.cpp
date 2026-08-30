class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(m + 1, 0));

        // Both empty
        dp[0][0] = 1;

        // String is empty
        // Pattern can match empty only if
        // it consists of x* x* x* ...
        for (int j = 2; j <= m; j++) {

            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                // Normal character OR '.'
                if (p[j - 1] == '.' ||
                    p[j - 1] == s[i - 1]) {

                    dp[i][j] =
                        dp[i - 1][j - 1];
                }

                // '*'
                else if (p[j - 1] == '*') {

                    // '*' matches zero occurrences
                    bool notTake =
                        dp[i][j - 2];

                    // '*' matches one/more occurrences
                    bool take = false;

                    if (p[j - 2] == '.' ||
                        p[j - 2] == s[i - 1]) {

                        take = dp[i - 1][j];
                    }

                    dp[i][j] = notTake || take;
                }
            }
        }

        return dp[n][m];
    }
};